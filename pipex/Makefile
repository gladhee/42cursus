# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 16:11:13 by heechoi           #+#    #+#              #
#    Updated: 2024/04/21 16:11:15 by heechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAGS= -Wall -Wextra -Werror
LIBFT= ./libft
LIBFT_HED= ./libft/libft.h

NAME= pipex

SRCS= ./pipex.c ./pipex_status.c ./pipex_parsing.c ./pipex_err.c

OBJS= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@make bonus -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -I$(LIBFT) -Llibft -lft

.c.o : $(SRCS)
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean :
	rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	rm -f ./Libft/libft.a

re : fclean all

.PHONY: all clean fclean re