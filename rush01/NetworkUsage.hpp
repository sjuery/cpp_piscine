#ifndef NETWORKUSAGE_HPP
# define NETWORKUSAGE_HPP
# include "IMonitorModule.hpp"

class NetworkUsage : public IMonitorModule{
	std::string _input;
	std::string _output;
	u_int64_t _previbytes;
	u_int64_t _prevobytes;
public:
	NetworkUsage();
	NetworkUsage(NetworkUsage const &);
	NetworkUsage &operator=(NetworkUsage const &);
	~NetworkUsage();

	void		update();
	void 		getNetworkThroughput(void);
	std::string getinput() const;
	std::string getoutput() const;
};

#endif
