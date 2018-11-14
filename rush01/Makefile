# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/04 14:33:42 by sjuery            #+#    #+#              #
#    Updated: 2018/10/14 19:07:18 by sjuery           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Run this to make SFML work
export DYLD_FALLBACK_LIBRARY_PATH=/nfs/2017/s/sjuery/.brew/Cellar/sfml/2.4.2_1/lib

NAME	= ft_gkrellm

SRC		= 	main.cpp \
			Hostname.cpp \
			OSInfo.cpp \
			DateTime.cpp \
			CPUInfo.cpp \
			CPUUsage.cpp \
			RAMUsage.cpp \
			NetworkUsage.cpp \
			TextDisplay.cpp \
			GraphicalDisplay.cpp \

OBJ 	= $(SRC:.c=.o)
CFLAG	= -Wall -Wextra -Werror -lncurses $(shell pkg-config --cflags sfml-graphics sfml-window sfml-system)
SFMLFLAG = $(shell pkg-config --libs sfml-graphics sfml-window sfml-system)
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	printf '\033[31m[...] %s\n\033[0m' "Creating gkrellm"
	g++ $(CFLAG) $(SFMLFLAG) $^ -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created gkrellm"

# pathupdate:
# 	@echo

clean:
	printf '\033[31m[...] %s\n\033[0m' "Cleaning gkrellm"
	/bin/rm -f *.o
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Cleaned gkrellm"

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all test
