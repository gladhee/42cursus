#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/wait.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0
# define ERR (-1)

typedef char			t_bool;

typedef long long		t_time;

typedef struct s_data
{
	void	*data;
	sem_t	mutex;
}				t_data;

typedef struct s_info
{
	int		num_of_philo;
	t_time	time_to_die;
	t_time	time_to_eat;
	t_time	time_to_sleep;
	int		num_of_must_eat;
	sem_t	*forks;
	t_time	start_time;
	sem_t	print;
	t_data	dead;
	t_data	is_finish;

}				t_info;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	t_data		time_of_eat;
	t_data		num_of_eat;
	pid_t		pid;
	t_info		*info;
	t_bool		(*eat)(struct s_philo *philo, t_fork *fork1, t_fork *fork2);
}				t_philo;


#endif