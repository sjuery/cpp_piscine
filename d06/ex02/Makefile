# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/04 14:33:42 by sjuery            #+#    #+#              #
#    Updated: 2018/10/10 17:51:04 by sjuery           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= identificator

SRC		= main.cpp \


OBJ 	= $(SRC:.c=.o)
CFLAG	= -Wall -Wextra -Werror
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	printf '\033[31m[...] %s\n\033[0m' "Creating identificator"
	clang++ $(CFLAG) $^ -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created identificator"

clean:
	printf '\033[31m[...] %s\n\033[0m' "Cleaning identificator"
	/bin/rm -f *.o
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Cleaned identificator"

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all test
