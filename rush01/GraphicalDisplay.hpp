#ifndef GRAPHICALDISPLAY_HPP
# define GRAPHICALDISPLAY_HPP
# include "IMonitorDisplay.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <unistd.h>
#include "Hostname.hpp"
#include "OSInfo.hpp"
#include "DateTime.hpp"
#include "CPUInfo.hpp"
#include "CPUUsage.hpp"
#include "RAMUsage.hpp"
#include "NetworkUsage.hpp"
#include "SFML/Graphics.hpp"

class GraphicalDisplay : public IMonitorDisplay {
	HostName *_hostname;
	OSInfo *_osinfo;
	DateTime *_datetime;
	CPUInfo *_cpuinfo;
	CPUUsage *_cpuusage;
	RAMUsage *_ramusage;
	NetworkUsage *_networkusage;

	size_t 		_moduellen;
	size_t 		_displaydepth;
	sf::Font _font;
public:
	GraphicalDisplay();
	GraphicalDisplay(GraphicalDisplay const &);
	GraphicalDisplay &operator=(GraphicalDisplay const &);
	~GraphicalDisplay();

	void	display(char *);
	sf::Text 	displayString(std::string, std::string, int, int);
};

#endif
