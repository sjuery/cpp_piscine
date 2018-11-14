#include "NetworkUsage.hpp"
#include <sys/sysctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <net/route.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

NetworkUsage::NetworkUsage()
{
	getNetworkThroughput();
}

NetworkUsage::NetworkUsage(NetworkUsage const & srcs)
{
	_input = srcs.getinput();
	_output = srcs.getoutput();
}

NetworkUsage &NetworkUsage::operator=(NetworkUsage const & srcs)
{
	_input = srcs.getinput();
	_output = srcs.getoutput();
	return *this;
}

NetworkUsage::~NetworkUsage() {}

void    NetworkUsage::getNetworkThroughput(void)
{
    /* Copied from stackoverflow. Thanks Stefan, you're the man for figuring this out */
    int        mib[] = { CTL_NET, PF_ROUTE, 0, 0, NET_RT_IFLIST2, 0 };
    char    *buf;
    size_t    len = 1024;

    sysctl(mib, 6, NULL, &len, NULL, 0);
    buf = new char[len];
    sysctl(mib, 6, buf, &len, NULL, 0);

    char *lim = buf + len;
    char *next = NULL;

    u_int64_t totalibytes = 0;
    u_int64_t totalobytes = 0;

    for (next = buf; next < lim; )
    {
        struct if_msghdr *ifm = reinterpret_cast<struct if_msghdr*>(next);
        next += ifm->ifm_msglen;

        if (ifm->ifm_type == RTM_IFINFO2)
        {
            struct if_msghdr2 *if2m = reinterpret_cast<struct if_msghdr2*>(ifm);

            totalibytes += if2m->ifm_data.ifi_ibytes;
            totalobytes += if2m->ifm_data.ifi_obytes;
        }
    }
	_input = std::to_string((totalibytes - _previbytes));
	_output = std::to_string((totalobytes - _prevobytes));
    _previbytes = totalibytes;
    _prevobytes = totalobytes;

    delete buf;
}

void	NetworkUsage::update()
{
	getNetworkThroughput();
}

std::string 	NetworkUsage::getinput() const
{
	return _input;
}

std::string 	NetworkUsage::getoutput() const
{
	return _output;
}
