#include "Player.class.hpp"
# include "Game.class.hpp"
#include <ncurses.h>
#include <iostream>

void		Player::init() {
	_hitPoints = 3;
	_damage = 1;
	_pos.x = 0;
	_pos.y = 1;
	_size.x = 1;
	_size.y = 1;
	_direction = 1;
	_value = 1;
}

Player::Player() {
	init();
	return ;
}

Player::Player(std::string type) {
	_type = type;
	init();
	return ;
}

Player::Player(Player const & that) {
	*this = that;
	return ;
}

Player::~Player() {

	return ;
}

Player &		Player::operator=(Player const & that) {
	if (this != &that) {

	}
	return *this;
}

// --------------------------------------------------------- //
// ---- Functions										---- //
// --------------------------------------------------------- //

void			Player::update(bool const * keys, t_render & win) {
	if (keys[LEFT]) {
		moveLeft(1);
	}
	if (keys[RIGHT]) {
		moveRight(win, 1);
	}
	if (keys[UP]) {
		moveUp(1);
	}
	if (keys[DOWN]) {
		moveDown(win, 1);
	}
	attron(COLOR_PAIR(1));
	mvprintw(getPos().y, getPos().x, "<>");
	attroff(COLOR_PAIR(1));
	return ;
}
