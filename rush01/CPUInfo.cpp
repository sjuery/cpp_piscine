#include "CPUInfo.hpp"
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysctl.h>

CPUInfo::CPUInfo()
{
	size_t bufflen = 128;
	char buff[128];

	module_name = "CPUInfo";
	sysctlbyname("machdep.cpu.brand_string",&buff,&bufflen,NULL,0);
	_name += buff;
    sysctlbyname("machdep.cpu.core_count", &_cores, &bufflen, NULL, 0);
    sysctlbyname("machdep.cpu.thread_count", &_threads, &bufflen, NULL, 0);
}

CPUInfo::CPUInfo(CPUInfo const & srcs)
{
	_name = srcs.getname();
	_cores = srcs.getcores();
	_threads = srcs.getthreads();
}

CPUInfo &CPUInfo::operator=(CPUInfo const & srcs)
{
	_name = srcs.getname();
	_cores = srcs.getcores();
	_threads = srcs.getthreads();
	return *this;
}

CPUInfo::~CPUInfo() {}

void	CPUInfo::update()
{
	std::cout << getname() << std::endl;
	std::cout << getcores() << std::endl;
	std::cout << getthreads() << std::endl;
}

std::string CPUInfo::getname() const
{
	return _name;
}

int CPUInfo::getcores() const
{
	return _cores;
}

int CPUInfo::getthreads() const
{
	return _threads;
}
