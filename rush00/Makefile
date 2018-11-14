NAME		= ft_retro

CC			= g++
CFLAGS		+= -Wall -Werror -Wextra -Wc++98-compat -lncurses -Wpedantic -fsanitize=address
INC			= -I inc

SRC_FILES	= main.cpp \
			  AGameEntity.class.cpp \
			  Player.class.cpp \
			  Game.class.cpp \
			  Bullet.class.cpp \
			  Enemy.class.cpp \
			  EBullet.class.cpp \

SRC			= $(addprefix src/, $(SRC_FILES))

BLUE		= \033[38;5;105;1m
GREEN		= \033[1;32m
NO_COLOR    = \033[m

# ---------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(SRC)
	@printf "%b" "$(GREEN)Compiling: $(BLUE)$(NAME)\n$(NO_COLOR)"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(INC)

fclean:
	rm $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME)

.PHONY: all fclean re test
