#include "ft_retro.hpp"
#include "Game.class.hpp"
#include "AGameEntity.class.hpp"
#include "Player.class.hpp"
#include "Enemy.class.hpp"
#include <ctime>
#include <ncurses.h>

void		Game::init() {
	bzero(_entities, sizeof(_entities));
	bzero(_bullets, sizeof(_bullets));
	begin = clock();
	_player = new Player();
	_score = 0;
	_ammo = 10;
	_numEntities = 0;
	_numBullets = 0;
	_timetospawn = 75;
	_timer = 0;
}

Game::Game() {
	init();
	return ;
}

Game::Game(Game const & that) {
	*this = that;
	return ;
}

Game::~Game() {

	return ;
}

Game &		Game::operator=(Game const & that) {
	if (this != &that) {

	}
	return *this;
}


// --------------------------------------------------------- //
// ---- Functions										---- //
// --------------------------------------------------------- //

void 			Game::endgame() {
	for (unsigned int i = 0; i < (sizeof(_entities) / sizeof(_entities[0])); i++) {
		if (_entities[i] != NULL) {
			_entities[i] = NULL;
			delete _entities[i];
		}
	}
	endwin();
	exit(0);
}

void 			Game::spawnBullets(t_vec _pos) {
	if(!_bullets[_numBullets])
		_bullets[_numBullets++] = new Bullet(_pos);
}

void 			Game::espawnBullets(t_vec _pos) {
	if(!_ebullets[_numEBullets])
		_ebullets[_numEBullets++] = new EBullet(_pos);
}

void 			Game::spawnEntities(void) {
	t_vec pos = {win.max_x-1, 0};

	int num = rand()%(3 + (int)(_score/1000));

	for(int i = 0; i < num; i++)
	{
		pos.y = rand()%win.max_y;
		if(!_entities[_numEntities])
		{
			int type = rand()%3;
			if(type == 1)
				_entities[_numEntities] = new Enemy("=");
			else if(type == 2)
				_entities[_numEntities] = new Enemy("<-");
			else
				_entities[_numEntities] = new Enemy("{");
			_entities[_numEntities]->setPos(pos);
		}
		_numEntities++;
	}
	_timetospawn = rand()%20;
	if (_timetospawn < 5 )
		_timetospawn = 5;
}

void 			Game::collisionCheck() {
	for (int i = 0; i <= _numEntities; i++) {
		if (_entities[i] != NULL) {
			if(_entities[i]->getPos().y == _player->getPos().y && _entities[i]->getPos().x == _player->getPos().x && _player->getHitPoints() == 1)
			{
				delete _player;
				endgame();
			}
			else if(_entities[i]->getPos().y == _player->getPos().y && _entities[i]->getPos().x == _player->getPos().x)
			{
				_entities[i] = NULL;
				delete _entities[i];
				_player->setHitPoints(_player->getHitPoints()-1);
			}
			else if (_entities[i]->getPos().x == 0)
			{
				_entities[i] = NULL;
				delete _entities[i];
			}
			else
			{
				for(int y = 0; y <= _numBullets; y++)
				{
					if (_bullets[y] && _entities[i]) {
						if((_entities[i]->getPos().y == _bullets[y]->getPos().y && _entities[i]->getPos().x == _bullets[y]->getPos().x) || (_entities[i]->getPos().y == _bullets[y]->getPos().y && _entities[i]->getPos().x - 1 == _bullets[y]->getPos().x))
						{
							_score += _entities[i]->getValue();
							_ammo += 1;
							_entities[i] = NULL;
							delete _entities[i];
							_bullets[y] = NULL;
							delete _bullets[y];
						}
						else if (_bullets[y]->getPos().x > win.max_x)
						{
							_bullets[y] = NULL;
							delete _bullets[y];
						}
					}
				}
			}
		}
	}
	for(int y = 0; y <= _numEBullets; y++)
	{
		if (_ebullets[y] && _player) {
			if(((_player->getPos().y == _ebullets[y]->getPos().y && _player->getPos().x == _ebullets[y]->getPos().x) || (_player->getPos().y == _ebullets[y]->getPos().y && _player->getPos().x - 1 == _ebullets[y]->getPos().x)) && _player->getHitPoints() == 1)
			{
				endgame();
			}
			else if (((_player->getPos().y == _ebullets[y]->getPos().y && _player->getPos().x == _ebullets[y]->getPos().x) || (_player->getPos().y == _ebullets[y]->getPos().y && _player->getPos().x - 1 == _ebullets[y]->getPos().x)))
			{
				_ebullets[y] = NULL;
				delete _ebullets[y];
				_player->setHitPoints(_player->getHitPoints()-1);
			}
			else if (_ebullets[y]->getPos().x < 0)
			{
				_ebullets[y] = NULL;
				delete _ebullets[y];
			}
		}
	}
}

void 			Game::updateAll() {
	if(_timetospawn-- == 0)
		spawnEntities();
	for(int i = 0; i < _numBullets; i++)
	{
		if (_bullets[i] != NULL) {
			_bullets[i]->update(keys, win);
		}
	}
	for(int i = 0; i < _numEBullets; i++)
	{
		if (_ebullets[i] != NULL) {
			_ebullets[i]->update(keys, win);
		}
	}
	if(keys[SPACE] && _ammo > 0)
	{
		_ammo--;
		spawnBullets(_player->getPos());
	}
	_player->update(keys, win);
	for (int i = 0; i <= _numEntities; i++) {
		if (_entities[i] != NULL) {
			if (rand()%250 == 7)
				espawnBullets(_entities[i]->getPos());
			_entities[i]->update(keys, win);
		}
	}
	if(_numEntities == 10000)
		_numEntities = 0;
	if(_numBullets == 10000)
		_numBullets = 0;
	if(_numEBullets == 10000)
		_numEBullets = 0;
	_score += (((float)(clock() - begin)/CLOCKS_PER_SEC) * 10);
}

void 			Game::printInfo() {
	attron(COLOR_PAIR(5));
	if(_timer-- != 0)
	{
		for(int i = 0; i < win.max_x/8; i++)
			mvprintw(rand()%win.max_y, rand()%win.max_x, "*");
		_timer = 4;
	}

	attroff(COLOR_PAIR(5));
	std::string score = "|Score: " + std::to_string(_score) + " | ";
	std::string ammo = "Bullets: " + std::to_string(_ammo) + " | ";
	std::string health = "Health: " + std::to_string(_player->getHitPoints()) + " | ";
	std::string times = "Time: " + std::to_string(((float)(clock() - begin)/CLOCKS_PER_SEC) * 100) + " |";
	attron(COLOR_PAIR(4));
	mvprintw(0, 0, score.c_str());
	mvprintw(0, strlen(score.c_str()), ammo.c_str());
	mvprintw(0, strlen(score.c_str()) + strlen(ammo.c_str()), health.c_str());
	mvprintw(0, strlen(health.c_str()) + strlen(score.c_str()) + strlen(ammo.c_str()), times.c_str());
	attroff(COLOR_PAIR(4));
}

void			Game::update() {
	erase();
	getmaxyx(stdscr, win.max_y, win.max_x);
	printInfo();
	collisionCheck();
	updateAll();
	refresh();
	return ;
}
