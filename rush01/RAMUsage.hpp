#ifndef RAMUSAGE_HPP
# define RAMUSAGE_HPP
# include "IMonitorModule.hpp"

class RAMUsage : public IMonitorModule{
	int64_t _physicalMemory;
	int64_t _memoryUsed;
public:
	RAMUsage();
	RAMUsage(RAMUsage const &);
	RAMUsage &operator=(RAMUsage const &);
	~RAMUsage();

	void		update();
	float getphysical() const;
	float getmemory() const;

	void setMemory();
	void setPhysical();
};

#endif
