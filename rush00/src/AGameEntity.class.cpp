#include "ft_retro.hpp"
#include "AGameEntity.class.hpp"
# include "Bullet.class.hpp"
#include "Game.class.hpp"

// --------------------------------------------------------- //
// ---- Constructors and Init							---- //
// --------------------------------------------------------- //

AGameEntity::AGameEntity() {
	init();
	return ;
}

AGameEntity::AGameEntity(std::string type)
	:	_type(type)
{
	init();
	return ;
}

AGameEntity::AGameEntity(AGameEntity const & that) {
	*this = that;
	return ;
}

AGameEntity::~AGameEntity() {

	return ;
}

AGameEntity &		AGameEntity::operator=(AGameEntity const & that) {
	if (this != &that) {
		setType(that.getType());
		setHitPoints(that.getHitPoints());
		setDamage(that.getDamage());
		setPos(that.getPos());
		setSize(that.getSize());
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & os, AGameEntity const & that) {
	os << that.getType();

	return os;
}

// --------------------------------------------------------- //
// ---- Functions										---- //
// --------------------------------------------------------- //

void		AGameEntity::init(void) {
	_hitPoints = 1;
	_damage = 1;
	_pos.x = MIN_X;
	_pos.y = MIN_Y;
	_size.x = 1;
	_size.y = 1;
	_direction = 1;
	_value = 1;
	_speed = 1;
}

void				AGameEntity::displayStatus() const {
	std::cout << "<" << getType() << "> ";
	std::cout << "HP: " << getHitPoints() << "; ";
	std::cout << "Pos: (" << getPos().x << ", " << getPos().y << "); ";
	std::cout << std::endl;
}

// --------------------------------------------------------- //
// ---- Movement										---- //
// --------------------------------------------------------- //

void		AGameEntity::moveUp(int amount) {
	//std::cout << "up" << std::endl;
	_pos.y -= amount;
	if (_pos.y < MIN_Y) {
		_pos.y = MIN_Y;
	}
	return ;
}

void		AGameEntity::moveDown(t_render & win, int amount) {
	//std::cout << "down" << std::endl;
	_pos.y += amount;
	if (_pos.y > win.max_y-1) {
		_pos.y = win.max_y-1;
	}
	return ;
}

void		AGameEntity::moveLeft(int amount) {
	//std::cout << "left" << std::endl;
	_pos.x -= amount;
	if (_pos.x < MIN_X) {
		_pos.x = MIN_X;
	}
	return ;
}

void		AGameEntity::moveRight(t_render & win, int amount) {
	//std::cout << "right" << std::endl;
	_pos.x += amount;
	if (_pos.x > win.max_x - 2) {
		_pos.x = win.max_x - 2;
	}
	return ;
}

// --------------------------------------------------------- //
// ---- Getters and Setters								---- //
// --------------------------------------------------------- //

std::string			AGameEntity::getType(void) const {
	return _type;
}

void				AGameEntity::setType(std::string nval) {
	_type = nval;
}

int					AGameEntity::getHitPoints(void) const {
	return _hitPoints;
}

void				AGameEntity::setHitPoints(int nval) {
	_hitPoints = nval;
}

int					AGameEntity::getDamage(void) const {
	return _damage;
}

void				AGameEntity::setDamage(int nval) {
	_damage = nval;
}

t_vec				AGameEntity::getPos(void) const {
	return _pos;
}

void				AGameEntity::setPos(t_vec nval) {
	_pos = nval;
}

t_vec				AGameEntity::getSize(void) const {
	return _size;
}

void				AGameEntity::setSize(t_vec nval) {
	_size = nval;
}

int				AGameEntity::getDirection(void) const {
	return _direction;
}

void				AGameEntity::setDirection(int nval) {
	_direction = nval;
}

int				AGameEntity::getValue(void) const {
	return _value;
}

void				AGameEntity::setValue(int nval) {
	_value = nval;
}
