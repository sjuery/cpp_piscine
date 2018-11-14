#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

# include "ft_retro.hpp"
# include "AGameEntity.class.hpp"
# include "Bullet.class.hpp"

class Enemy : public AGameEntity {
public:
	Enemy();
	Enemy(std::string);
	Enemy(Enemy const &);
	Enemy &operator=(Enemy const &);
	~Enemy();

	void		init(void);
	void		update(bool const *, t_render &);

private:
};

#endif
