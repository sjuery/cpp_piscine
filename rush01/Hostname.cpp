#include "Hostname.hpp"
#include <unistd.h>

HostName::HostName()
{
	char buff[256];

	module_name = "HostName";
	gethostname(buff, 256);
	_hostname += buff;
	getlogin_r(buff, 256);
	_login += buff;
}

HostName::HostName(HostName const & srcs)
{
	_hostname = srcs.gethost();
	_login = srcs.getlogin();
}

HostName &HostName::operator=(HostName const & srcs)
{
	_hostname = srcs.gethost();
	_login = srcs.getlogin();
	return *this;
}

HostName::~HostName() {}

void	HostName::update()
{
	std::cout << gethost() << std::endl;
	std::cout << getlogin() << std::endl;
}

std::string 	HostName::gethost() const
{
	return _hostname;
}

std::string 	HostName::getlogin() const
{
	return _login;
}
