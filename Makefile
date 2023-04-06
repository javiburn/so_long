# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 14:44:25 by jsarabia          #+#    #+#              #
#    Updated: 2023/04/06 14:46:38 by jsarabia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

GREEN = \033[0;92m
RED = \033[0;91m
RESET = \033[0;39m

CC = gcc

INCDIR = inc
INCMLX = mlx

LIBFT = libft
PRINTF = ft_printf
GNL = get_next_line
# MLX = mlx

LIBFTOUT = libft/libft.a
PRINTFOUT = ft_printf/libftprintf.a
GNLOUT = get_next_line/get_next_line.a

#OBJS =

OBJS = so_long.o map_elements.o check_map.o print_errors.o free_all.o checking.o init_map.o presskey.o movement.o
#check_map.c ft_map_coord.c ft_text_map.c read_map.c presskey.c movement.c ft_check.c ft_free_all.c print_errors.c

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): compile_libft compile_printf compile_gnl $(OBJS)\
   #	compile_mlx \
	$(LIBFT) $(PRINTF) $(GNL)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTOUT) $(PRINTFOUT) $(GNLOUT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(GREEN)so_long successfully compiled"

compile_libft:
	@make bonus -C libft/

compile_printf:
	@make all -C ft_printf/

compile_gnl:
	@make all -C get_next_line/

#compile_mlx:
#	@make all -C mlx/
#	@echo"$(GREEN)Minilibx was successfully compiled"

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@make clean -C libft/
	@make clean -C ft_printf/
	@make clean -C get_next_line/
	/bin/rm -f *.o
#	@make clean -C mlx/

fclean: clean
	@make fclean -C libft/
	@make fclean -C ft_printf/
	@make fclean -C get_next_line/
	rm so_long
#	@make fclean -C mlx/

re: fclean all

.PHONY: clean fclean re
