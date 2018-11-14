#ifndef EBULLET_CLASS_HPP
# define EBULLET_CLASS_HPP

# include "ft_retro.hpp"
# include "AGameEntity.class.hpp"
# include "Game.class.hpp"

class EBullet : public AGameEntity {
public:
	EBullet(t_vec);
	EBullet(std::string);
	EBullet(EBullet const &);
	EBullet &operator=(EBullet const &);
	~EBullet();

	void		init();
	void		update(bool const *, t_render &);

private:

};

#endif
