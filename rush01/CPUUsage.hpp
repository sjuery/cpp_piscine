#ifndef CPUUSAGE_HPP
# define CPUUSAGE_HPP
# include "IMonitorModule.hpp"

class CPUUsage : public IMonitorModule{
	double _user;
	double _system;
	double _idle;
public:
	CPUUsage();
	CPUUsage(CPUUsage const &);
	CPUUsage &operator=(CPUUsage const &);
	~CPUUsage();

	void		update();
	void		calUsage();
	double 		getuser() const;
	double  	getsystem() const;
	double 		getidle() const;
};

#endif
