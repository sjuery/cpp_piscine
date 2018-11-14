#include "GraphicalDisplay.hpp"

GraphicalDisplay::GraphicalDisplay()
{
	_hostname = new HostName();
	_osinfo = new OSInfo();
	_datetime = new DateTime();
	_cpuinfo = new CPUInfo();
	_cpuusage = new CPUUsage();
	_ramusage = new RAMUsage();
	_networkusage = new NetworkUsage();
	_displaydepth = 10;
	if (!_font.loadFromFile("resources/Viga.ttf"))
	{
	    std::cout << "Font not found" << std::endl;
	}
}

GraphicalDisplay::GraphicalDisplay(GraphicalDisplay const & srcs)
{
	(void)srcs;
}

GraphicalDisplay &GraphicalDisplay::operator=(GraphicalDisplay const & srcs)
{
	(void)srcs;
	return *this;
}

GraphicalDisplay::~GraphicalDisplay() {}

sf::Text 	GraphicalDisplay::displayString(std::string desc, std::string info, int row, int depth)
{
	sf::Text text;

	text.setFont(_font);
	text.setString(desc + info);
	text.setCharacterSize(35);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(row, depth);
	return(text);
}

void	GraphicalDisplay::display(char *moduels)
{
	for(size_t i = 0; i < 8; i++)
		if(moduels[i] == 1)
			_moduellen++;

	sf::RenderWindow window(sf::VideoMode(850, 1400), "My window");
	while(window.isOpen())
	{
		_displaydepth = 10;
		sf::Event evnt;
		while(window.pollEvent(evnt))
		{
			switch(evnt.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}
		}
		sleep(1);
		_datetime->update();
		_cpuusage->update();
		_ramusage->update();
		_networkusage->update();
		window.clear(sf::Color::Black);
		//Host Name
		if(moduels[0])
		{
			window.draw(displayString("HostInfo:", "", 10, _displaydepth));
			_displaydepth += 50;
			window.draw(displayString("HostName - ", _hostname->gethost(), 30, _displaydepth));
			_displaydepth += 50;
			window.draw(displayString("Login - ", _hostname->getlogin(), 30, _displaydepth));
			_displaydepth += 75;
		}
		//OS Info
		if(moduels[1])
		{
			window.draw(displayString("OSInfo:", "", 10, _displaydepth));
			_displaydepth += 50;
			window.draw(displayString("System - ", _osinfo->getsystem(), 30, _displaydepth));
			_displaydepth += 50;
			window.draw(displayString("Version - ", _osinfo->getversion(), 30, _displaydepth));
			_displaydepth += 50;
			window.draw(displayString("TimeStamp - ", _osinfo->gettimestamp(), 30, _displaydepth));
			_displaydepth += 50;
			window.draw(displayString("Machine - ", _osinfo->getmachine(), 30, _displaydepth));
			_displaydepth += 75;
		}
		//Date Time
		if(moduels[2])
		{
			window.draw(displayString("Date/Time:", "", 10, _displaydepth));
			_displaydepth += 50;
			window.draw(displayString("Date - ", _datetime->getdate(), 30, _displaydepth));
			_displaydepth += 50;
			window.draw(displayString("Time - ", _datetime->gettime(), 30, _displaydepth));
			_displaydepth += 75;
		}
		//CPU Info
		if(moduels[3])
		{
			window.draw(displayString("CPU Info:", "", 10, _displaydepth));
			_displaydepth += 50;
			window.draw(displayString("Name - ", _cpuinfo->getname(), 30, _displaydepth));
			_displaydepth += 50;
			window.draw(displayString("Cores/Threads - ", std::to_string(_cpuinfo->getcores()) + "/" + std::to_string(_cpuinfo->getthreads()), 30, _displaydepth));
			_displaydepth += 75;
		}
		//CPU Usage
		if(moduels[4])
		{
			window.draw(displayString("CPU Usage:", "", 10, _displaydepth));
			_displaydepth += 50;
			window.draw(displayString("System - ", std::to_string(_cpuusage->getsystem()), 30, _displaydepth));
			_displaydepth += 50;
			window.draw(displayString("User - ", std::to_string(_cpuusage->getuser()), 30, _displaydepth));
			_displaydepth += 50;
			window.draw(displayString("Idle - ", std::to_string(_cpuusage->getidle()), 30, _displaydepth));
			_displaydepth += 75;
		}
		//RAM Usage
		if(moduels[5])
		{
			window.draw(displayString("RAM Usage:", "", 10, _displaydepth));
			_displaydepth += 50;
			window.draw(displayString("Physical - ", std::to_string(_ramusage->getphysical()), 30, _displaydepth));
			_displaydepth += 50;
			window.draw(displayString("Memory Used - ", std::to_string(_ramusage->getmemory()), 30, _displaydepth));
			_displaydepth += 75;
		}
		//Network Usage
		if(moduels[6])
		{
			window.draw(displayString("Network Usage:", "", 10, _displaydepth));
			_displaydepth += 50;
			window.draw(displayString("InputBytes - ", _networkusage->getinput() + " Bytes/s", 30, _displaydepth));
			_displaydepth += 50;
			window.draw(displayString("OutputBytes - ", _networkusage->getoutput() + " Bytes/s", 30, _displaydepth));
			_displaydepth += 75;
		}
		//Magic
		if(moduels[7])
		{
			window.draw(displayString("The Pony Is Dead", " :`('", 10, _displaydepth));
		}
		window.display();
	}
}
