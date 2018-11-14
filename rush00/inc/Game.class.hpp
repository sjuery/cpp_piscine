#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include <iostream>
# include "ft_retro.hpp"
# include "AGameEntity.class.hpp"
# include "Bullet.class.hpp"
# include "EBullet.class.hpp"

class Game {
public:
	Game();
	Game(Game const &);
	Game &operator=(Game const &);
	~Game();

	void		update(void);
	void 		endgame(void);
	void 		collisionCheck(void);
	void 		updateAll(void);
	void 		printInfo(void);
	void 		spawnEntities(void);
	void		spawnBullets(t_vec _pos);
	void 		espawnBullets(t_vec _pos);

	t_render	win;
	bool		keys[5];
	AGameEntity * 	_player;
	AGameEntity *	_entities[10000];
	AGameEntity * 	_bullets[10000];
	AGameEntity * 	_ebullets[10000];

private:
	clock_t 		begin;
	void			init(void);
	int 			_timer;
	int 			_timetospawn;
	int				_numEntities;
	int 			_numBullets;
	int 			_numEBullets;
	int 			_score;
	int 			_ammo;
};

#endif
