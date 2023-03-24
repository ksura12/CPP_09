# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 09:24:12 by ksura             #+#    #+#              #
#    Updated: 2023/03/24 10:32:51 by ksura            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := btc
CC = c++
CFLAGS := -Wall -Werror -Wextra -std=c++98 -D DEBUG=0
DFLAGS := -Wall -Werror -Wextra -std=c++98 -g  -D DEBUG=1
HEADER = ./header
SRCDIR = src/
OBJDIR = build/

SRC := main.cpp

GREEN = \033[0;32m
RED = \033[0;31m
COLOR_DEFAULT = \033[0m

OBJS = ${SRC:.cpp=.o}

OBJECTS_PREF := $(addprefix $(OBJDIR), $(OBJS))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS_PREF) $(OBJDIR)
	@$(CC) $(FLAGS) $(OBJECTS_PREF) -I$(HEADER) -o $@
	@echo "$(GREEN)$(NAME) was created"

$(OBJECTS_PREF): build/%.o : src/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER) $(INCLUDES)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) was deleted"

re: fclean all

debug: CFLAGS = $(DFLAGS)
debug: re ./$(NAME)

val:
	valgrind --leak-check=full -s ./$(NAME)

leak:
	leaks --atExit -- ./$(NAME)