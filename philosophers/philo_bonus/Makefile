# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 19:48:55 by heechoi           #+#    #+#              #
#    Updated: 2024/07/10 19:48:58 by heechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo_bonus

SRCS = philo_bonus.c philo_free_bonus.c philo_ft_bonus.c philo_init_bonus.c \
		philo_init_info_bonus.c philo_monitor_bonus.c philo_process_bonus.c \
		philo_process_utils_bonus.c philo_status_bonus.c philo_utils_bonus.c \
		philo_ft_strjoin_bonus.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lpthread

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re