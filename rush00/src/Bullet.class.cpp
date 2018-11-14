#include "Bullet.class.hpp"
#include <ncurses.h>
#include <iostream>

void		Bullet::init() {
	_hitPoints = 1;
	_damage = 1;
	_pos.x = 0;
	_pos.y = 0;
	_size.x = 1;
	_size.y = 1;
	_direction = 1;
	_value = 1;
}

Bullet::Bullet(t_vec ppos) {
	init();
	_pos.x = ppos.x;
	_pos.y = ppos.y;
	return ;
}

Bullet::Bullet(std::string type) {
	_type = type;
	init();
	return ;
}

Bullet::Bullet(Bullet const & that) {
	*this = that;
	return ;
}

Bullet::~Bullet() {

	return ;
}

Bullet &		Bullet::operator=(Bullet const & that) {
	if (this != &that) {

	}
	return *this;
}


// --------------------------------------------------------- //
// ---- Functions										---- //
// --------------------------------------------------------- //

void			Bullet::update(bool const * keys, t_render & win) {
	//std::cout << "updating Bullet!" << std::endl;
	(void)keys;
	(void)win;
	_pos.x++;
	attron(COLOR_PAIR(3));
	mvprintw(getPos().y, getPos().x, "~");
	attroff(COLOR_PAIR(3));
	return ;
}
