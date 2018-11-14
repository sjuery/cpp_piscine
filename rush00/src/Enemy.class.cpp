#include "Enemy.class.hpp"
#include <ncurses.h>
#include <iostream>

void		Enemy::init() {
	_hitPoints = 1;
	_damage = 1;
	_pos.x = 0;
	_pos.y = 0;
	_size.x = 2;
	_size.y = 1;
	_direction = 1;
	_value = 10;
	_speed = 2;
}

Enemy::Enemy() {
	init();
	return ;
}

Enemy::Enemy(std::string type) {
	_type = type;
	init();
	return ;
}

Enemy::Enemy(Enemy const & that) {
	*this = that;
	return ;
}

Enemy::~Enemy() {

	return ;
}

Enemy &		Enemy::operator=(Enemy const & that) {
	if (this != &that) {

	}
	return *this;
}


// --------------------------------------------------------- //
// ---- Functions										---- //
// --------------------------------------------------------- //

void			Enemy::update(bool const * keys, t_render & win) {
	(void)win;
	(void)keys;
	if(_speed-- == 0)
	{
		int ran = rand()%100;
		if(ran == 1)
			moveUp(1);
		else if (ran == 2)
			moveDown(win, 1);
		moveLeft(1);
		_speed = 2;
	}
	attron(COLOR_PAIR(2));
	mvprintw(getPos().y, getPos().x, getType().c_str());
	attron(COLOR_PAIR(2));
	return ;
}
