#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "Hostname.hpp"
#include "OSInfo.hpp"
#include "DateTime.hpp"
#include "CPUInfo.hpp"
#include "CPUUsage.hpp"
#include "RAMUsage.hpp"
#include "TextDisplay.hpp"
#include "GraphicalDisplay.hpp"
#include <stdio.h>
#include <string.h>

int main() {
	char display;
	std::string moduels;
	char cleanmoduels[8] = {0};

	std::cout << "Moduels Types:" << std::endl;
	std::cout << "1 - HostName" << std::endl;
	std::cout << "2 - OSInfo" << std::endl;
	std::cout << "3 - Date/Time" << std::endl;
	std::cout << "4 - CPUInfo" << std::endl;
	std::cout << "5 - CPUUsage" << std::endl;
	std::cout << "6 - RAMUsage" << std::endl;
	std::cout << "7 - NetworkInfo" << std::endl;
	std::cout << "8 - TopSecret" << std::endl;
	std::cout << "Please select Display Type: ";
	std::cin >> moduels;

	for(size_t i = 0; i < moduels.length(); i++)
	{
		if(moduels[i] >= '0' && moduels[i] <= '8')
			cleanmoduels[moduels[i]-'1'] = 1;
	}

	// for(size_t i = 0; i < 8; i++)
	// {
	// 	if(cleanmoduels[i] == 1)
	// 		std::cout << "Good number is " << i+1 << std::endl;
	// 	// std::cout << cleanmoduels[i] << std::endl;
	// }

	std::cout << "Display Types:" << std::endl;
	std::cout << "G = Graphical Display (SFML)" << std::endl;
	std::cout << "S = Standard Display (NCURSUS)" << std::endl;
	std::cout << "Please select Display Type: ";
	std::cin >> display;

	std::cout << display << std::endl;
	std::cout << moduels << std::endl;
	if(display == 'S')
	{
		TextDisplay *textdisplay = new TextDisplay();
		textdisplay->display(cleanmoduels);
	}
	else if(display == 'G')
	{
		GraphicalDisplay *graphicaldisplay = new GraphicalDisplay();
		graphicaldisplay->display(cleanmoduels);
	}

	return 0;
}
