# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/04 14:33:42 by sjuery            #+#    #+#              #
#    Updated: 2018/09/30 20:39:58 by sjuery           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
LIST = megaphone

SRC = $(addsuffix .cpp, $(LIST))
OBJ_DIR = obj
OBJ = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(LIST)))

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
.SILENT:

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	printf '\033[31m[...] %s\n\033[0m' "Creating Megaphone"
	clang++ $(CPPFLAGS) -o $@ $^
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created Megaphone"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC)
	clang++ $(CPPFLAGS) -MMD -c $< -o $@

clean:
	printf '\033[31m[...] %s\n\033[0m' "Cleaning Sully Program"
	rm -f $(OBJ)

fclean:
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fully Cleaning Sully Program"
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re docs
