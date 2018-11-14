#ifndef AGAMEENTITY_CLASS_HPP
# define AGAMEENTITY_CLASS_HPP

# include "ft_retro.hpp"

class AGameEntity {
public:
	AGameEntity();
	AGameEntity(std::string);
	AGameEntity(AGameEntity const &);
	AGameEntity &operator=(AGameEntity const &);
	virtual ~AGameEntity();

	virtual void	update(bool const *, t_render &) = 0;

	void		displayStatus(void) const;

	// Movement:
	void		moveUp(int);
	void		moveDown(t_render &, int);
	void		moveLeft(int);
	void		moveRight(t_render &, int);

	std::string	getType(void) const;
	void		setType(std::string);
	int			getHitPoints(void) const;
	void		setHitPoints(int);
	int			getDamage(void) const;
	void		setDamage(int);
	t_vec		getPos(void) const;
	void		setPos(t_vec);
	t_vec		getSize(void) const;
	void		setSize(t_vec);
	int			getDirection(void) const;
	void		setDirection(int);
	int			getValue(void) const;
	void		setValue(int);

private:
	void			init(void);

protected:
	std::string	_type;
	int			_hitPoints;
	int			_damage;
	t_vec		_pos;
	t_vec		_size;
	int			_direction;
	int			_value;
	int 		_speed;

//	std::string	_avatarStrings[];

};

std::ostream &		operator<<(std::ostream &, AGameEntity const &);

#endif
