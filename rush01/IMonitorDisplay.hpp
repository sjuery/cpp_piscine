#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP
# include <iostream>

class IMonitorDisplay {
public:
	IMonitorDisplay() {};
	IMonitorDisplay(IMonitorDisplay const &) {};
	IMonitorDisplay &operator=(IMonitorDisplay const &);
	virtual ~IMonitorDisplay() {};

	virtual void	display(char *) = 0;

};

#endif
