#ifndef CPUINFO_HPP
# define CPUINFO_HPP
# include "IMonitorModule.hpp"

class CPUInfo : public IMonitorModule{
	std::string _name;
	int _cores;
	int _threads;
public:
	CPUInfo();
	CPUInfo(CPUInfo const &);
	CPUInfo &operator=(CPUInfo const &);
	~CPUInfo();

	void		update();
	std::string getname() const;
	int  		getcores() const;
	int 		getthreads() const;
};

#endif
