# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 12:09:36 by heechoi           #+#    #+#              #
#    Updated: 2023/11/28 14:15:56 by heechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAGS = -Wall -Wextra -Werror
AP= ar
ARFLAGS = rcs
RM = rm -f
LIBFT = ./libft
NAME= libftprintf.a

SRCS= ft_printf.c ft_print_hex.c ft_print_ptr.c ft_print_unsigned_nbr.c \
		ft_print_char.c ft_print_str.c ft_print_nbr.c
OBJS= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		make -C $(LIBFT)
		cp ./libft/libft.a ./$(NAME)
		$(AR) $(ARFLAGS) $@ $^

.c.o : $(SRCS)
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean :
		$(RM) $(OBJS)
		@make clean -C $(LIBFT)

fclean : clean
		$(RM) $(NAME)
		@make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
