#include "CPUUsage.hpp"
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <sys/sysctl.h>
#include <sys/types.h>
#include <mach/mach.h>
#include <mach/processor_info.h>
#include <mach/mach_host.h>
#include <stdio.h>
#include <unistd.h>

CPUUsage::CPUUsage()
{
	calUsage();
}

CPUUsage::CPUUsage(CPUUsage const & srcs)
{
	_system = srcs.getsystem();
	_user = srcs.getuser();
	_idle = srcs.getidle();
}

CPUUsage &CPUUsage::operator=(CPUUsage const & srcs)
{
	_system = srcs.getsystem();
	_user = srcs.getuser();
	_idle = srcs.getidle();
	return *this;
}

CPUUsage::~CPUUsage() {}

void	CPUUsage::update()
{
	calUsage();
}

void	CPUUsage::calUsage()
{
	processor_cpu_load_info_t cpuLoad;
	mach_msg_type_number_t processorMsgCount;
	natural_t processorCount;

	static uint64_t preSystemTime, preUserTime, preIdleTime, pretotal;
	uint64_t totalSystemTime = 0, totalUserTime = 0, totalIdleTime = 0, totalCPUTime = 0;

	host_processor_info(mach_host_self(), PROCESSOR_CPU_LOAD_INFO, &processorCount, (processor_info_array_t *)&cpuLoad, &processorMsgCount);

	for (natural_t i = 0; i < processorCount; i++)
	{
		// Calc load types and totals, with guards against 32-bit overflow
		// (values are natural_t)
		uint64_t system = 0, user = 0, idle = 0, total = 0;

		system = cpuLoad[i].cpu_ticks[CPU_STATE_SYSTEM];
		user = cpuLoad[i].cpu_ticks[CPU_STATE_USER];
		idle = cpuLoad[i].cpu_ticks[CPU_STATE_IDLE];

		total = system + user + idle;

		if (total < 1)
			total = 1;

		totalCPUTime += total;
		totalSystemTime += system;
		totalUserTime += user;
		totalIdleTime += idle;
	}

	totalCPUTime -= pretotal;
	totalSystemTime -=  preSystemTime;
	totalUserTime -= preUserTime;
	totalIdleTime -= preIdleTime;

	pretotal += totalCPUTime;
	preSystemTime += totalSystemTime;
	preUserTime += totalUserTime;
	preIdleTime += totalIdleTime;

	double onePercent = totalCPUTime/100.0f;

	_system = (double)totalSystemTime/(double)onePercent;
	_user = (double)totalUserTime/(double)onePercent;
	_idle = (double)totalIdleTime/(double)onePercent;
}

double	CPUUsage::getuser() const
{
	return _user;
}

double	CPUUsage::getsystem() const
{
	return _system;
}

double	CPUUsage::getidle() const
{
	return _idle;
}
