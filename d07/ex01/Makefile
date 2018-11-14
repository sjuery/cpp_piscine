# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/04 14:33:42 by sjuery            #+#    #+#              #
#    Updated: 2018/10/11 16:29:46 by sjuery           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Iter

SRC		= iter.cpp \


OBJ 	= $(SRC:.c=.o)
CFLAG	= -Wall -Wextra -Werror
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	printf '\033[31m[...] %s\n\033[0m' "Creating Iter"
	clang++ $(CFLAG) $^ -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created Iter"

clean:
	printf '\033[31m[...] %s\n\033[0m' "Cleaning Iter"
	/bin/rm -f *.o
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Cleaned Iter"

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all test
