#ifndef TEXTDISPLAY_HPP
# define TEXTDISPLAY_HPP
# include "IMonitorDisplay.hpp"
#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <ncurses.h>
#include <unistd.h>
#include "Hostname.hpp"
#include "OSInfo.hpp"
#include "DateTime.hpp"
#include "CPUInfo.hpp"
#include "CPUUsage.hpp"
#include "RAMUsage.hpp"
#include "NetworkUsage.hpp"

class TextDisplay : public IMonitorDisplay{
	int	_row;
	int	_col;
public:
	TextDisplay();
	TextDisplay(TextDisplay const &);
	TextDisplay &operator=(TextDisplay const &);
	~TextDisplay();

	void	init_ncurse();
	void	display(char *);
	void	hostnameDisplay(HostName*, int);
	void	osinfoDisplay(OSInfo*, int);
	void	datetimeDisplay(DateTime *, int);
	void	cpuinfoDisplay(CPUInfo *, int);
	void	cpuusageDisplay(CPUUsage *, int);
	void	ramusageDisplay(RAMUsage *, int);
	void	networkusageDisplay(NetworkUsage *, int);
	void	ponyDisplay(int);
};

#endif
