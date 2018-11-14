#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

# include "ft_retro.hpp"
# include "AGameEntity.class.hpp"

class Player : public AGameEntity {
public:
	Player();
	Player(std::string);
	Player(Player const &);
	Player &operator=(Player const &);
	~Player();

	void		init(void);
	void		update(bool const *, t_render &);

private:
};

#endif
