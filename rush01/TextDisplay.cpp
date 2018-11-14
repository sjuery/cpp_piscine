#include "TextDisplay.hpp"
#define BTGIB 1073741824
#include <curses.h>
#include <ncurses.h>
#include <iomanip>
#include <sstream>

TextDisplay::TextDisplay()
{

}

TextDisplay::TextDisplay(TextDisplay const & srcs)
{
	(void)srcs;
}

TextDisplay &TextDisplay::operator=(TextDisplay const & srcs)
{
	(void)srcs;
	return *this;
}

TextDisplay::~TextDisplay() {}

void	TextDisplay::init_ncurse()
{
	initscr();
	raw();
	noecho();
	timeout(0);
	curs_set(FALSE);
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	start_color();
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_RED);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_CYAN);
	init_pair(7, COLOR_WHITE, COLOR_CYAN);
	init_pair(8, COLOR_RED, COLOR_BLACK);
}

void	TextDisplay::hostnameDisplay(HostName *hostname, int y)
{
	WINDOW *hostnameCol = derwin(stdscr, 4, _col - 4, y, 2);
	box(hostnameCol, '|', '-');
	mvwprintw(hostnameCol, 0, _col / 2 - 5, "Host Name");

	mvwprintw(hostnameCol, 1, 2, "Host : ");
	mvwprintw(hostnameCol, 1, 9, hostname->gethost().c_str());
	mvwprintw(hostnameCol, 2, 2, "Login: ");
	mvwprintw(hostnameCol, 2, 9, hostname->getlogin().c_str());
	wrefresh(hostnameCol);
}

void	TextDisplay::osinfoDisplay(OSInfo *osinfo, int y)
{
	WINDOW *osinfoCol = derwin(stdscr, 7, _col - 4, y, 2);
	box(osinfoCol, '|', '-');
	mvwprintw(osinfoCol, 0, _col / 2 - 4, "OS Info");
	mvwprintw(osinfoCol, 1, 2, "System   :");
	mvwprintw(osinfoCol, 1, 13, osinfo->getsystem().c_str());
	mvwprintw(osinfoCol, 2, 2, "Version  :");
	mvwprintw(osinfoCol, 2, 13, osinfo->getversion().c_str());
	mvwprintw(osinfoCol, 3, 2, "Timestamp: ");
	mvwprintw(osinfoCol, 3, 13, osinfo->gettimestamp().c_str());
	mvwprintw(osinfoCol, 4, 2, "Machine  :");
	mvwprintw(osinfoCol, 4, 13, osinfo->getmachine().c_str());
	wrefresh(osinfoCol);
}

void	TextDisplay::datetimeDisplay(DateTime *datetime, int y)
{
	datetime->update();
	WINDOW *datetimeCol = derwin(stdscr, 4, _col - 4, y, 2);
	box(datetimeCol, '|', '-');
	mvwprintw(datetimeCol, 0, _col / 2 - 5, "Date & Time");

	mvwprintw(datetimeCol, 1, 2, "Date :");
	mvwprintw(datetimeCol, 1, 9, datetime->getdate().c_str());
	mvwprintw(datetimeCol, 2, 2, "Time :");
	mvwprintw(datetimeCol, 2, 9, datetime->gettime().substr(0,2).c_str());
	mvwprintw(datetimeCol, 2, 11, "h ");
	mvwprintw(datetimeCol, 2, 13, datetime->gettime().substr(3,2).c_str());
	mvwprintw(datetimeCol, 2, 15, "m ");
	mvwprintw(datetimeCol, 2, 17, datetime->gettime().substr(6,2).c_str());
	mvwprintw(datetimeCol, 2, 19, "s ");
	wrefresh(datetimeCol);
}

void	TextDisplay::cpuinfoDisplay(CPUInfo *cpuinfo, int y)
{
	WINDOW *cpuinfoCol = derwin(stdscr, 5, _col -4 , y, 2);
	box(cpuinfoCol, '|', '-');
	mvwprintw(cpuinfoCol, 0, _col / 2 - 5, "CPU Info");

	mvwprintw(cpuinfoCol, 1, 2, "CPU     :");
	mvwprintw(cpuinfoCol, 1, 12, cpuinfo->getname().c_str());
	mvwprintw(cpuinfoCol, 2, 2, "Cores   :");
	mvwprintw(cpuinfoCol, 2, 12, std::to_string(cpuinfo->getcores()).c_str());
	mvwprintw(cpuinfoCol, 3, 2, "threads :");
	mvwprintw(cpuinfoCol, 3, 12, std::to_string(cpuinfo->getthreads()).c_str());
	wrefresh(cpuinfoCol);
}

void	TextDisplay::cpuusageDisplay(CPUUsage *cpuusage, int y)
{
	static int i = 0;
	WINDOW *cpuusageCol = derwin(stdscr, 5, _col -4, y, 2);
	if (i != 0)
		werase(cpuusageCol);

	box(cpuusageCol, '|', '-');
	mvwprintw(cpuusageCol, 0, _col / 2 - 5, "CPU Usage");

	if (i % 5 == 0)
		cpuusage->update();
	mvwprintw(cpuusageCol, 1, 2, "system :");
	mvwprintw(cpuusageCol, 1, 11, std::to_string(cpuusage->getsystem()).substr(0, 5).c_str());
	mvwprintw(cpuusageCol, 1, 17, "%%");
	mvwprintw(cpuusageCol, 2, 2, "user   :");
	mvwprintw(cpuusageCol, 2, 11, std::to_string(cpuusage->getuser()).substr(0, 5).c_str());
	mvwprintw(cpuusageCol, 2, 17, "%%");
	mvwprintw(cpuusageCol, 3, 2, "idle   :");
	mvwprintw(cpuusageCol, 3, 11, std::to_string(cpuusage->getidle()).substr(0, 5).c_str());
	mvwprintw(cpuusageCol, 3, 17, "%%");
	wrefresh(cpuusageCol);
	i++;
}

void	TextDisplay::ramusageDisplay(RAMUsage *ramusage, int y)
{

	static int i = 0;
	WINDOW *ramusageCol = derwin(stdscr, 4, _col -4 , y, 2);
	box(ramusageCol, '|', '-');

	mvwprintw(ramusageCol, 0, _col / 2 - 5, "Ram Usage");

	if (i % 5 == 0)
		ramusage->update();
	mvwprintw(ramusageCol, 1, 2, "physical memory :");
	mvwprintw(ramusageCol, 1, 20, std::to_string(ramusage->getphysical()).substr(0, 4).c_str());
	mvwprintw(ramusageCol, 1, 25, "GB");
	mvwprintw(ramusageCol, 2, 2, "memory used     :");
	mvwprintw(ramusageCol, 2, 20, std::to_string(ramusage->getmemory()).substr(0, 4).c_str());
	mvwprintw(ramusageCol, 2, 25, "GB");
	wrefresh(ramusageCol);
	i++;
}

void	TextDisplay::networkusageDisplay(NetworkUsage *networkusage, int y)
{

	static int i = 0;
	WINDOW *networkusageCol = derwin(stdscr, 4, _col -4 , y, 2);
	box(networkusageCol, '|', '-');

	mvwprintw(networkusageCol, 0, _col / 2 - 5, "Network Usage");

	if (i % 5 == 0)
		networkusage->update();
	mvwprintw(networkusageCol, 1, 2, "input  :");
	mvwprintw(networkusageCol, 1, 10, networkusage->getinput().c_str());
	mvwprintw(networkusageCol, 1, 21, "Bytes/s");
	mvwprintw(networkusageCol, 2, 2, "output :");
	mvwprintw(networkusageCol, 2, 10, networkusage->getoutput().c_str());
	mvwprintw(networkusageCol, 2, 21, "Bytes/s");
	wrefresh(networkusageCol);
	i++;
}

void	TextDisplay::ponyDisplay(int y)
{
	static int i = 0;
	if (i % 5 == 0)
	{
		WINDOW *ponyCol = derwin(stdscr, 6, _col -4 , y, 2);
		werase(ponyCol);
		box(ponyCol, '|', '-');

		mvwprintw(ponyCol, 0, _col / 2 - 9, "Pony Running - 5 secs");
		mvwprintw(ponyCol, 1, 50, ",");
		mvwprintw(ponyCol, 2, 50, "/,`\\");
		mvwprintw(ponyCol, 3, 50, "` | \\____\\");
		mvwprintw(ponyCol, 4, 50, "_(      ) \\");
		mvwprintw(ponyCol, 5, 50, "\\-\\~~~_|\\  \\");
		mvwprintw(ponyCol, 6, 50, "   \\ `   \\  `");
		mvwprintw(ponyCol, 7, 50, "   `     `");
		wrefresh(ponyCol);
	}
	if (i % 5 == 1)
	{
		WINDOW *ponyCol = derwin(stdscr, 6, _col -4 , y, 2);
		werase(ponyCol);
		box(ponyCol, '|', '-');

		mvwprintw(ponyCol, 0, _col / 2 - 9, "Pony Running - 5 secs");
		mvwprintw(ponyCol, 1, 40, ",~~_");
		mvwprintw(ponyCol, 2, 40, "|/\\ =_ _ ~");
		mvwprintw(ponyCol, 3, 40, " _( )_( )\\~~");
		mvwprintw(ponyCol, 4, 40, "\\,\\  _|\\ \\~~~");
		mvwprintw(ponyCol, 5, 40, "   \\`   \\");
		mvwprintw(ponyCol, 6, 40, "   `    `");
		wrefresh(ponyCol);
	}
	if (i % 5 == 2)
	{
		WINDOW *ponyCol = derwin(stdscr, 6, _col -4 , y, 2);
		werase(ponyCol);
		box(ponyCol, '|', '-');

		mvwprintw(ponyCol, 0, _col / 2 - 9, "Pony Running - 5 secs");
		mvwprintw(ponyCol, 1, 30, ",~~_");
		mvwprintw(ponyCol, 2, 30, "|/\\ =_ _ ~");
		mvwprintw(ponyCol, 3, 30, " _( )_( )\\~~");
		mvwprintw(ponyCol, 4, 30, "\\,\\  _|\\ \\~~~");
		mvwprintw(ponyCol, 5, 30, "   \\`   \\");
		mvwprintw(ponyCol, 6, 30, "   `    `");
		wrefresh(ponyCol);
	}
	if (i % 5 == 3)
	{
		WINDOW *ponyCol = derwin(stdscr, 6, _col -4 , y, 2);
		werase(ponyCol);
		box(ponyCol, '|', '-');

		mvwprintw(ponyCol, 0, _col / 2 - 9, "Pony Running - 5 secs");
		mvwprintw(ponyCol, 1, 20, ",~~_");
		mvwprintw(ponyCol, 2, 20, "|/\\ =_ _ ~");
		mvwprintw(ponyCol, 3, 20, " _( )_( )\\~~");
		mvwprintw(ponyCol, 4, 20, "\\,\\  _|\\ \\~~~");
		mvwprintw(ponyCol, 5, 20, "   \\`   \\");
		mvwprintw(ponyCol, 6, 20, "   `    `");
		wrefresh(ponyCol);
	}
	if (i % 5 == 4)
	{
		WINDOW *ponyCol = derwin(stdscr, 6, _col -4 , y, 2);
		werase(ponyCol);
		box(ponyCol, '|', '-');

		mvwprintw(ponyCol, 0, _col / 2 - 9, "Pony Running - 5 secs");
		mvwprintw(ponyCol, 1, 5, "((^--__");
		mvwprintw(ponyCol, 2, 5, "| /\\  --___ __");
		mvwprintw(ponyCol, 3, 5, "   (  /  \\  ) \\");
		mvwprintw(ponyCol, 4, 5, "   / |~~~~/  \\  \\");
		mvwprintw(ponyCol, 5, 5, " /    \\ /      \\");
		wrefresh(ponyCol);
	}
	i++;
}

void	TextDisplay::display(char *module)
{
	init_ncurse();
	clear();
	int yscreen = 0, xscreen = 0, y;

	HostName		*hostname = new HostName();
	OSInfo			*osinfo = new OSInfo();
	DateTime		*datetime = new DateTime();
	CPUInfo			*cpuinfo = new CPUInfo();
	CPUUsage		*cpuusage = new CPUUsage();
	RAMUsage		*ramusage = new RAMUsage();
	NetworkUsage	*networkusage = new NetworkUsage();

// derwin(WINDOW *orig, int nlines, int ncols, int begin_y, int begin_x)
// mvwprintw(WINDOW *win, int y, int x, const char *fmt)

	cpuusage->update();
	while (1)
	{
		y = 0;
		yscreen = _row;
		xscreen = _col;
		getmaxyx(stdscr, _row, _col);

		if (_row != yscreen || _col != xscreen)
			clear();
		attron(COLOR_PAIR(7));
		box(stdscr, 0, 0);
		attroff(COLOR_PAIR(7));
		wrefresh(stdscr);

		WINDOW *titleCol = derwin(stdscr, 5, _col - 4, 1, 2);
		box(titleCol, ' ', '=');
		mvwprintw(titleCol, 2, _col / 2 - 6, "ft_gkerllm");
		wrefresh(titleCol);

		attron(COLOR_PAIR(2));
		y += 7;
		if (module[0])
		{
			hostnameDisplay(hostname, y);
			y += 5;
		}
		if (module[1])
		{
			osinfoDisplay(osinfo, y);
			y += 8;
		}
		if (module[2])
		{
			datetimeDisplay(datetime, y);
			y += 5;
		}
		if (module[3])
		{
			cpuinfoDisplay(cpuinfo, y);
			y += 6;
		}
		if (module[4])
		{
			cpuusageDisplay(cpuusage, y);
			y += 6;
		}
		if (module[5])
		{
			ramusageDisplay(ramusage, y);
			y += 5;
		}
		if (module[6])
		{
			networkusageDisplay(networkusage, y);
			y += 5;
		}
		if (module[7])
		{
			ponyDisplay(y);
		}

		attroff(COLOR_PAIR(2));

		int dir = getch();
		switch (dir)
		{
		case 27: case 'q': endwin(); return;
		default: break;
		}
		sleep(1);
	}
	endwin();
}
