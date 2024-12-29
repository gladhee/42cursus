# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 21:37:15 by heechoi           #+#    #+#              #
#    Updated: 2024/12/16 18:06:26 by heechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SHELL = /bin/bash
sp    = /-\|/
idx		=	0

LIBRARIES_DIR = libraries/
LIBFT_DIR = $(LIBRARIES_DIR)libft/
MLX_DIR = $(LIBRARIES_DIR)minilibx/

LIBFT_FLAGS = -I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft
MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

HEADERS = includes/

SRC_DIR = srcs/
ERROR_DIR = error/
GNL_DIR = get_next_line/
PARSE_DIR = parse/
RAYCASTER_DIR = raycaster/
UTILS_DIR = utils/

ERROR = error.c
GNL = get_next_line.c get_next_line_utils.c
PARSE = parse.c parse_map.c parse_ident.c \
		bfs.c bfs_deque_cmd.c bfs_deque_utils.c
RAYCASTER = init_ray.c init_mlx.c key_event.c run.c \
			raycasting.c wall_texture.c load_image.c \
			move_player.c
UTILS = parse_util.c parse_util_2.c free.c

SRC += main.c
SRC += $(addprefix $(ERROR_DIR), $(ERROR))
SRC += $(addprefix $(GNL_DIR), $(GNL))
SRC += $(addprefix $(PARSE_DIR), $(PARSE))
SRC += $(addprefix $(RAYCASTER_DIR), $(RAYCASTER))
SRC += $(addprefix $(UTILS_DIR), $(UTILS))
SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(SRCS:.c=.o)

NAME = cub3D

all: $(NAME) $(HEADERS) $(LIBFT_DIR) $(MLX_DIR)

$(NAME): $(OBJS) $(HEADERS) $(LIBFT_DIR) $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@cp $(MLX_DIR)libmlx.a .
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -I$(HEADERS) $(LIBFT_FLAGS) $(OBJS) -o $(NAME)
	@printf "\b \033[32m✓\033[0m\n"

.c.o: $(HEADERS) $(LIBFT_DIR) $(MLX_DIR)
	$(eval idx = $(shell expr $(idx) + 1))
	$(eval t_idx = $(shell expr $(idx) % 4 + 1))
	$(eval chr = $(shell echo $(sp) | cut -c $(t_idx)))
	@if [ $(idx) = 1 ]; then\
		echo -n "Loading ... ";\
	fi
	@printf "\b$(chr)"
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(HEADERS) -I$(LIBFT_DIR) -I$(MLX_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@$(RM) $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLX_DIR) clean
	@$(RM) libmlx.a
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re