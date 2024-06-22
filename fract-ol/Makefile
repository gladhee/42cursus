# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 19:58:06 by heechoi           #+#    #+#              #
#    Updated: 2024/05/22 21:05:02 by heechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = ./mlx
MLX_HED = ./mlx/mlx.h
MLX = libmlx.dylib

LIBFT_DIR = ./Libft
LIB_LIBFT = libft.a
LIBFT_HED= ./Libft/libft.h

HEADER_DIR = includes

NAME = fractol

SRC = fractol.c fractol_error.c ft_atod.c mlx_event.c mlx_utils.c
SRCS = $(addprefix srcs/, $(SRC))

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make bonus -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	cp $(MLX_DIR)/libmlx.dylib .
	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit

.c.o : $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -Imlx -Ilibft -I$(HEADER_DIR)

clean:
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(MLX)

re: fclean all

.PHONY: all clean fclean re
