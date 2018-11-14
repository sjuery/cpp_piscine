# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/04 14:33:42 by sjuery            #+#    #+#              #
#    Updated: 2018/10/10 18:03:38 by sjuery           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= whatever

SRC		= whatever.cpp \


OBJ 	= $(SRC:.c=.o)
CFLAG	= -Wall -Wextra -Werror
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	printf '\033[31m[...] %s\n\033[0m' "Creating who cares"
	clang++ $(CFLAG) $^ -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created who cares"

clean:
	printf '\033[31m[...] %s\n\033[0m' "Cleaning who cares"
	/bin/rm -f *.o
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Cleaned who cares"

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all test
