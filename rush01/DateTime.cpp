#include "DateTime.hpp"
#include <unistd.h>

DateTime::DateTime()
{
	update();
}

DateTime::DateTime(DateTime const & srcs)
{
	_date = srcs.getdate();
	_time = srcs.gettime();
}

DateTime &DateTime::operator=(DateTime const & srcs)
{
	_date = srcs.getdate();
	_time = srcs.gettime();
	return *this;
}

DateTime::~DateTime() {}

void	DateTime::update()
{
	time_t udate = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::string date = ctime(&udate);

	_date = date.substr (0,10) + date.substr (19,5);
	_time = date.substr (11,8);
}

std::string 	DateTime::getdate() const
{
	return _date;
}

std::string 	DateTime::gettime() const
{
	return _time;
}
