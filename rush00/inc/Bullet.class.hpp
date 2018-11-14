#ifndef BULLET_CLASS_HPP
# define BULLET_CLASS_HPP

# include "ft_retro.hpp"
# include "AGameEntity.class.hpp"
# include "Game.class.hpp"

class Bullet : public AGameEntity {
public:
	Bullet(t_vec);
	Bullet(std::string);
	Bullet(Bullet const &);
	Bullet &operator=(Bullet const &);
	~Bullet();

	void		init();
	void		update(bool const *, t_render &);

private:

};

#endif
