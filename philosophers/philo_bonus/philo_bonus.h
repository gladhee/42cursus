/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:49:04 by heechoi           #+#    #+#             */
/*   Updated: 2024/07/10 19:51:04 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef char		t_bool;

typedef long long	t_time;

# define TRUE 1
# define FALSE 0
# define ERROR (-1)
# define EXIT_FULL 2
# define EXIT_DIED 3

typedef struct s_data
{
	void		*data;
	sem_t		*sem;
}				t_data;

typedef struct s_info
{
	int		num_of_philo;
	t_time	time_to_die;
	t_time	time_to_eat;
	t_time	time_to_sleep;
	int		num_of_must_eat;
	t_time	start_time;
	sem_t	*forks;
	sem_t	*print;
	t_data	dead;
}				t_info;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	pid_t		pid;
	t_data		time_of_eat;
	char		*sem_time;
	t_data		num_of_eat;
	char		*sem_num;
	t_info		*info;
}				t_philo;

/* philo_free_bonus.c */
void	free_info(t_info *info);
void	free_philo(t_philo *philo, int num_of_philo);

/* philo_ft_bonus.c */
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);

/* philo_ft_strjoin_bonus.c */
char	*ft_strjoin(char const *s1, char const *s2);

/* philo_init_bonus.c */
t_philo	*init_philo(t_info *info);

/* philo_init_info_bonus.c */
t_info	*init_info(int argc, char **argv);

/* philo_monitor_bonus.c */
void	*philo_monitor(void *arg);

/* philo_process_bonus.c */
void	philo_process(t_philo *philo);

/* philo_process_utils_bonus.c */
void	philo_eat(t_philo *philo);

/* philo_status_bonus.c */
t_bool	is_dead(t_info *info);
t_bool	set_dead(t_info *info);

/* philo_utils_bonus.c */
void	exit_error(char *str);
t_time	get_time(void);
t_bool	wait_time(t_time time);
t_time	philo_print(t_philo *philo, char *str);
char	*sem_name_philo(int id, char *str);

#endif