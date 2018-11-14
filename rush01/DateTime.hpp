#ifndef DATETIME_HPP
# define DATETIME_HPP
# include "IMonitorModule.hpp"

class DateTime : public IMonitorModule{
	std::string _date;
	std::string _time;
public:
	DateTime();
	DateTime(DateTime const &);
	DateTime &operator=(DateTime const &);
	~DateTime();

	void		update();
	std::string getdate() const;
	std::string gettime() const;
};

#endif
