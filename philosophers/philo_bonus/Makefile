CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo_bonus

SRCS = philo_bonus.c philo_free_bonus.c philo_init_bonus.c \
		philo_monitor_bonus.c philo_exit_status_bonus.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lpthread

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
