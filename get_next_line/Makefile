# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsarabia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 13:09:33 by jsarabia          #+#    #+#              #
#    Updated: 2023/04/05 14:35:05 by jsarabia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

GREEN = \033[0;92m
RED = \033[0;91m

OBJS = get_next_line_bonus.o get_next_line_utils_bonus.o

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs get_next_line.a $(OBJS) get_next_line_bonus.h
	@echo "$(GREEN)GNL was successfully compiled"

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f  *.o
	@echo "$(RED)Every .c and .o from get_next_line were removed"

fclean: clean
	rm -f $(NAME)
	@echo "$(RED)GNL was successfully removed"

re: fclean all

.PHONY: clean fclean re
