#include "EBullet.class.hpp"
#include <ncurses.h>
#include <iostream>

void		EBullet::init() {
	_hitPoints = 1;
	_damage = 1;
	_pos.x = 0;
	_pos.y = 0;
	_size.x = 1;
	_size.y = 1;
	_direction = 1;
	_value = 1;
}

EBullet::EBullet(t_vec ppos) {
	init();
	_pos.x = ppos.x;
	_pos.y = ppos.y;
	return ;
}

EBullet::EBullet(std::string type) {
	_type = type;
	init();
	return ;
}

EBullet::EBullet(EBullet const & that) {
	*this = that;
	return ;
}

EBullet::~EBullet() {

	return ;
}

EBullet &		EBullet::operator=(EBullet const & that) {
	if (this != &that) {

	}
	return *this;
}


// --------------------------------------------------------- //
// ---- Functions										---- //
// --------------------------------------------------------- //

void			EBullet::update(bool const * keys, t_render & win) {
	//std::cout << "updating EBullet!" << std::endl;
	(void)keys;
	(void)win;
	_pos.x--;
	attron(COLOR_PAIR(3));
	mvprintw(getPos().y, getPos().x, "-");
	attroff(COLOR_PAIR(3));
	return ;
}
