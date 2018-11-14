#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP
# include <iostream>

class IMonitorModule {
public:
	IMonitorModule() {};
	IMonitorModule(IMonitorModule const &) {};
	IMonitorModule &operator=(IMonitorModule const &);
	virtual ~IMonitorModule() {};

	virtual void	update() = 0;

protected:
	std::string		module_name;
};

#endif
