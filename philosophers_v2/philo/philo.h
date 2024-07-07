#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0
# define ERR (-1)
# define P_ERR 2

typedef char			t_bool;

typedef long long		t_time;

typedef pthread_mutex_t	t_mutex;

typedef struct s_data
{
	void	*data;
	t_mutex	mutex;
}				t_data;

typedef struct s_fork
{
	t_bool	fork;
	t_mutex	mutex;
}				t_fork;

typedef struct s_info
{
	int		num_of_philo;
	t_time	time_to_die;
	t_time	time_to_eat;
	t_time	time_to_sleep;
	int		num_of_must_eat;
	t_fork	*forks;
	t_time	start_time;
	t_mutex	print;
	t_data	dead;
	t_data	order;
}				t_info;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_data		time_of_eat;
	t_data		num_of_eat;
	t_info		*info;
	t_bool		(*eat)(struct s_philo *philo, t_fork *fork1, t_fork *fork2);
}				t_philo;

/* philo.c */
t_bool	exit_error(void);

/* philo_free */
void	free_info(t_info *info);
void	free_philo(t_philo *philo, int philo_num);
void	error_free(t_info *info, t_philo *philo, int i);

/* philo_init.c */
t_info	*init_info(int argc, char **argv);
t_philo	*init_philo(t_info *info);

/* philo_init_utils.c */
t_bool	init_arg(t_info *info, int argc, char **argv);
t_bool	init_info_data(t_info *info);
void	init_philo_set(t_philo *philo, t_info *info, int i);
t_bool	init_philo_data(t_philo *philo, t_mutex *time, t_mutex *num);
t_bool	init_order(t_info *info);

/* philo_monitor.c */
t_bool	philo_monitor(t_info *info, t_philo *philo);

/* philo_status.c */
t_bool	set_dead(t_info *info);
t_bool	is_dead(t_info *info);
t_bool	next_order(t_info *info);
int		get_late_order(t_info *info);

/* philo_thread.c */
t_bool	philo_wait(t_time set);
t_bool	philo_sleep(t_philo *philo);
t_bool	philo_think(t_philo *philo);
void	*philo_thread(void *arg);

/* philo_thread_utils.c */
t_bool	philo_eat(t_philo *philo, t_fork *fork1, t_fork *fork2);

/* philo_utils.c */
t_time	get_time(void);
t_time	philo_print(t_philo *philo, char *str);

#endif