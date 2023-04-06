# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 11:45:24 by jsarabia          #+#    #+#              #
#    Updated: 2023/04/05 15:06:59 by jsarabia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

GREEN = \033[0;92m
RED = \033[0;91m

OBJS = ft_printf.o ft_putstr_fd.o ft_putchar_fd.o ft_putaddress.o ft_callocprintf.o ft_strlcpyprintf.o ft_putnbr_fd.o ft_putunsigned.o ft_puthexamin.o ft_puthexamay.o

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs libftprintf.a $(OBJS) ft_printf.h
	@echo "$(GREEN)Printf was successfully compiled"

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	/bin/rm -f *.o
	@echo "$(RED)Every .c and .o from ft_printf were removed"

fclean: clean
	/bin/rm -f $(NAME)
	@echo "$(RED)Printf was successfully removed"

re: fclean all
