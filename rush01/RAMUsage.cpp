#include "RAMUsage.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <mach/mach.h>
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>
#include <iostream>
#include <unistd.h>
#include <iomanip>

#define BTGIB 1073741824

RAMUsage::RAMUsage()
{
	update();
}

RAMUsage::RAMUsage(RAMUsage const & srcs)
{
	_physicalMemory = srcs.getphysical();
	_memoryUsed = srcs.getmemory();
}

RAMUsage &RAMUsage::operator=(RAMUsage const & srcs)
{
	_physicalMemory = srcs.getphysical();
	_memoryUsed = srcs.getmemory();
	return *this;
}

RAMUsage::~RAMUsage() {}

void	RAMUsage::update()
{
	setPhysical();
	setMemory();
	// std::cout << std::fixed << std::setprecision(2) << static_cast<float>(getphysical()) / BTGIB << std::endl;
	// std::cout << std::fixed << std::setprecision(2) <<  << std::endl;
}

void 	RAMUsage::setPhysical()
{
	int mib[2];
	size_t length;
	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	length = sizeof(int64_t);
	sysctl(mib, 2, &_physicalMemory, &length, NULL, 0);
}

void 	RAMUsage::setMemory()
{
	mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
	vm_statistics_data_t vmstat;
	if(KERN_SUCCESS != host_statistics(mach_host_self(), HOST_VM_INFO, (host_info_t)&vmstat, &count))
	    return ;
	_memoryUsed = ((int64_t)vmstat.active_count + (int64_t)vmstat.inactive_count + (int64_t)vmstat.wire_count) * getpagesize();
}

float RAMUsage::getphysical() const
{
	return (static_cast<float>((double)_physicalMemory / (double)BTGIB));
}

float RAMUsage::getmemory() const
{
	return (static_cast<float>((double)_memoryUsed / (double)BTGIB));
}
