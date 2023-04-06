# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsarabia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 16:54:26 by jsarabia          #+#    #+#              #
#    Updated: 2023/04/05 14:29:39 by jsarabia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

GREEN = \033[0;92m
RED = \033[0;91m
DEFAULT = \033[0;39m


OBJS = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_strlcpy.o ft_strlcat.o ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o ft_atoi.o ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o ft_strmapi.o ft_striteri.o ft_putendl_fd.o

OBJSBONUS = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs libft.a $(OBJS) libft.h
	@echo "$(GREEN)Libft was successfully compiled"

bonus: $(OBJSBONUS) $(OBJS)
	ar rcs libft.a $(OBJSBONUS) $(OBJS) libft.h

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	/bin/rm -f *.o
	@echo "$(RED)Every .c and .o from the libft were removed"

fclean: clean
	/bin/rm -f $(NAME)
	@echo "$(RED)Libft was successfully removed"

re: fclean all

.PHONY: clean fclean re
