#include "AGameEntity.class.hpp"
#include "Player.class.hpp"
#include "Game.class.hpp"
#include "ft_retro.hpp"
#include <ncurses.h>
#include <iostream>
#include <unistd.h>

void render_frame(Game & game) {
	int c;
	usleep(30000);
	c = getch();
	game.keys[DOWN] = false;
	game.keys[UP] = false;
	game.keys[RIGHT] = false;
	game.keys[LEFT] = false;
	game.keys[SPACE] = false;
	if(c == KEY_RIGHT)
		game.keys[RIGHT] = true;
	else if(c == KEY_LEFT)
		game.keys[LEFT] = true;
	if(c == KEY_UP)
		game.keys[UP] = true;
	else if(c == KEY_DOWN)
		game.keys[DOWN] = true;
	if(c == ' ')
		game.keys[SPACE] = true;
	game.update();
}

int main(void)
{
	srand(time(0));
	newterm(getenv("TERM"), stdout, stdin);
	curs_set(FALSE);
	raw();
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);

	Player player("player");

	Game game;

	while(1)
	{
		render_frame(game);
	}
}
