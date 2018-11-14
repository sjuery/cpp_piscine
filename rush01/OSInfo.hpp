#ifndef OSINFO_HPP
# define OSINFO_HPP
# include "IMonitorModule.hpp"

class OSInfo : public IMonitorModule{
	std::string _system;
	std::string _version;
	std::string _timestamp;
	std::string _machine;
public:
	OSInfo();
	OSInfo(OSInfo const &);
	OSInfo &operator=(OSInfo const &);
	~OSInfo();

	void		update();
	std::string getsystem() const;
	std::string getversion() const;
	std::string gettimestamp() const;
	std::string getmachine() const;
};

#endif
