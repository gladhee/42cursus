# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 12:59:25 by heechoi           #+#    #+#              #
#    Updated: 2023/10/30 17:35:14 by heechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS= -Wall -Wextra -Werror
AR= ar
ARFLAGS= rcs
RM= rm -f
NAME= libft.a

SRCS= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
OBJS= $(SRCS:.c=.o)

BONUS_SRCS= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BONUS_OBJS= $(BONUS_SRCS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES= $(OBJS) $(BONUS_OBJS)
else
	OBJ_FILES = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES)
		$(AR) $(ARFLAGS) $@ $^

bonus :
		@make WITH_BONUS=1 all

.c.o : $(SRCS)
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean :
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
