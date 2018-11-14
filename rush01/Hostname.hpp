#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP
# include "IMonitorModule.hpp"

class HostName : public IMonitorModule{
	std::string _hostname;
	std::string _login;
public:
	HostName();
	HostName(HostName const &);
	HostName &operator=(HostName const &);
	~HostName();

	void		update();
	std::string gethost() const;
	std::string getlogin() const;
};

#endif
