#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

# include <string>

# define MIN_X 0
# define MIN_Y 2

# define MAX_ENTITIES 1000

enum	e_keys {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	SPACE
};

struct t_render {
	float x;
	float y;
	int max_y;
	int max_x;
	float next_x;
	int direction;
};

struct	t_vec {
	float	x;
	float	y;
};

#endif
