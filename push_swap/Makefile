# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 21:29:50 by heechoi           #+#    #+#              #
#    Updated: 2024/06/13 13:24:02 by heechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
NAME_BONUS = checker

LIBFT = libft.a
LIBFT_DIR = libft
LIBFT_LIB = -L $(LIBFT_DIR) -lft

SRC = cmd_deque.c cmd_push.c cmd_r_rotate.c cmd_rotate.c cmd_swap.c push_swap.c arg_handle.c \
		deque_utils.c radix.c q_sort.c indexing.c error_handle.c radix_utils.c \
		push_swap_utils.c cmd_atob.c cmd_btoa.c normalize.c convert_base.c
SRC_BONUS = checker_bonus.c cmd_deque_bonus.c cmd_push_bonus.c cmd_r_rotate_bonus.c cmd_rotate_bonus.c cmd_swap_bonus.c \
		deque_utils_bonus.c parsing_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c

SRCS = $(addprefix mandatory/, $(SRC))
SRCS_BONUS = $(addprefix bonus/, $(SRC_BONUS))

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS_BONUS)
	SRC_FILES = $(SRCS_BONUS)
	NAME = $(NAME_BONUS)
else
	OBJ_FILES = $(OBJS)
	SRC_FILES = $(SRCS)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBFT_LIB)

bonus:
	@make WITH_BONUS=1 all

.c.o: $(SRC_FILES)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re