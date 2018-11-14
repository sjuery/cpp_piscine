# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/04 14:33:42 by sjuery            #+#    #+#              #
#    Updated: 2018/10/10 17:52:40 by sjuery           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= serialize

SRC		= 	main.cpp \


OBJ 	= $(SRC:.c=.o)
CFLAG	= -Wall -Wextra -Werror
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	printf '\033[31m[...] %s\n\033[0m' "Creating serializer"
	clang++ $(CFLAG) $^ -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created serializer"

clean:
	printf '\033[31m[...] %s\n\033[0m' "Cleaning serializer"
	/bin/rm -f *.o
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Cleaned serializer"

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all test
