#include "OSInfo.hpp"
#include <unistd.h>
#include <iostream>
#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/sysctl.h>

OSInfo::OSInfo()
{
	struct utsname sysinfo;
	uname(&sysinfo);

	module_name = "OSInfo";
	_system = sysinfo.sysname;
	_version = sysinfo.release;
	_timestamp = sysinfo.version;
	_timestamp = _timestamp.substr (30,28);
	_machine = sysinfo.machine;
}

OSInfo::OSInfo(OSInfo const & srcs)
{
	_system = srcs.getsystem();
	_version = srcs.getversion();
	_timestamp = srcs.gettimestamp();
	_machine = srcs.getmachine();
}

OSInfo &OSInfo::operator=(OSInfo const & srcs)
{
	_system = srcs.getsystem();
	_version = srcs.getversion();
	_timestamp = srcs.gettimestamp();
	_machine = srcs.getmachine();
	return *this;
}

OSInfo::~OSInfo() {}

void	OSInfo::update()
{
	std::cout << getsystem() << std::endl;
	std::cout << getversion() << std::endl;
	std::cout << gettimestamp() << std::endl;
	std::cout << getmachine() << std::endl;
}

std::string OSInfo::getsystem() const
{
	return _system;
}

std::string OSInfo::getversion() const
{
	return _version;
}

std::string OSInfo::gettimestamp() const
{
	return _timestamp;
}

std::string OSInfo::getmachine() const
{
	return _machine;
}
