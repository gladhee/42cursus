CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SHELL = /bin/bash
sp    = /-\|/
idx		=	0

LIBRARIES_DIR = libraries/
LIBFT_DIR = $(LIBRARIES_DIR)libft/
MLX_DIR = $(LIBRARIES_DIR)mlx/

LIBFT_FLAGS = -I(LIBFT_DIR) -L(LIBFT_DIR) -lft
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

HEADER = includes/

SRC_DIR = srcs/
PARSE_DIR = parse/
ERROR_DIR = error/

PARSE = parse.c
ERROR = map_error.c

SRC += main.c
SRC += $(addprefix $(PARSE_DIR), $(PARSE))
SRC += $(addprefix $(ERROR_DIR), $(ERROR))
SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(SRCS:.c=.o)

NAME = cub3D

all: $(NAME) $(HEADER) $(LIBFT_DIR) $(MLX_DIR)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(HEADER) $(LIBFT_FLAGS) $(MLX_FLAGS)
	@printf "\b \033[32m✓\033[0m\n"

.c.o:
	$(eval idx = $(shell expr $(idx) + 1))
	$(eval t_idx = $(shell expr $(idx) % 4 + 1))
	$(eval chr = $(shell echo $(sp) | cut -c $(t_idx)))
	@if [ $(idx) = 1 ]; then\
		echo -n "Loading ... ";\
	fi
	@printf "\b$(chr)"
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(HEADER) -I$(LIBFT_DIR) -I$(MLX_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@$(RM) $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLX_DIR) clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re