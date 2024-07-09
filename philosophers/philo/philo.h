/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:17:24 by heechoi           #+#    #+#             */
/*   Updated: 2024/07/09 13:12:20 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef char			t_bool;

typedef long long		t_time;

typedef pthread_mutex_t	t_mutex;

# define TRUE 1
# define FALSE 0
# define ERROR -1

typedef struct s_data
{
	void	*data;
	t_mutex	mutex;
}				t_data;

typedef struct s_fork
{
	t_bool	*is_used;
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
	t_mutex	print;
	t_time	start_time;
	t_data	dead;
	t_data	order;
}				t_info;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	t_data		time_of_eat;
	t_data		num_of_eat;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_info		*info;
}				t_philo;

/* philo_free.c */
void	destroy_forks(t_fork *forks, int num_of_philo);
void	destroy_philo_data(t_philo *philo);
void	free_philo(t_philo *philo, int num_of_philo);
void	free_info(t_info *info);

/* philo_init.c */
t_philo	*init_philo(t_info *info);
t_bool	init_order(t_info *info);

/* philo_init_info.c */
t_info	*init_info(int argc, char **argv);

/* philo_monitor.c */
t_bool	philo_monitor(t_info *info, t_philo *philo);

/* philo_status.c */
t_bool	set_dead(t_info *info);
t_bool	is_dead(t_info *info);
int		get_order(t_info *info);
t_bool	next_order(t_info *info);

/* philo_thread.c */
void	*philo_thread(void *arg);

/* philo_thread_utils.c */
t_bool	philo_eat(t_philo *philo, t_fork *fork1, t_fork *fork2);

/* philo_utils.c */
t_time	get_time(void);
//t_bool	philo_wait(t_time set);
t_bool	wait_time(t_time time);
t_time	philo_print(t_philo *philo, char *str);
int		ft_atoi(const char *str);

#endif
