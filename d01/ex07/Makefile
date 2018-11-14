# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/04 14:33:42 by sjuery            #+#    #+#              #
#    Updated: 2018/10/03 23:14:15 by sjuery           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace
LIST = replace

SRC = $(addsuffix .cpp, $(LIST))
OBJ_DIR = obj
OBJ = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(LIST)))

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
.SILENT:

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	printf '\033[31m[...] %s\n\033[0m' "Creating Replace Program"
	clang++ $(CPPFLAGS) -o $@ $^
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created Replace Program"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC)
	clang++ $(CPPFLAGS) -MMD -c $< -o $@

clean:
	printf '\033[31m[...] %s\n\033[0m' "Cleaning Replace Program"
	rm -f $(OBJ)

fclean:
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fully Cleaning Replace Program"
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re docs
