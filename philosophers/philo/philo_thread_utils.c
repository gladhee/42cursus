#include "philo.h"


t_bool	philo_take_fork(t_philo *philo, t_fork *fork1, t_fork *fork2)
{
	if (pthread_mutex_lock(&fork1->mutex))
		return (FALSE);
	fork1->fork = TRUE;
	if (philo_print(philo, "has taken a fork") == ERR)
	{
		fork1->fork = FALSE;
		pthread_mutex_unlock(&fork1->mutex);
		return (FALSE);
	}
	if (fork1 == fork2)
	{
		while (!is_dead(philo->info))
			usleep(100);
		return (FALSE);
	}
	if (pthread_mutex_lock(&fork2->mutex))
	{
		fork1->fork = FALSE;
		pthread_mutex_unlock(&fork1->mutex);
		return (FALSE);
	}
	fork2->fork = TRUE;
	if (philo_print(philo, "has taken a fork") == ERR)
	{
		fork1->fork = FALSE;
		fork2->fork = FALSE;
		pthread_mutex_unlock(&fork1->mutex);
		pthread_mutex_unlock(&fork2->mutex);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	philo_update_time_of_eat(t_philo *philo, t_time time)
{
	if (pthread_mutex_lock(&philo->time_of_eat.mutex))
		return (FALSE);
	*((t_time *)philo->time_of_eat.data) = time;
	if (pthread_mutex_unlock(&philo->time_of_eat.mutex))
		return (FALSE);
	return (TRUE);
}

t_bool	philo_update_num_of_eat(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->num_of_eat.mutex))
		return (FALSE);
	*((int *)philo->num_of_eat.data) += 1;
	if (pthread_mutex_unlock(&philo->num_of_eat.mutex))
		return (FALSE);
	return (TRUE);

}

// todo 뮤텍스 최적화
t_bool	philo_eat_odd(t_philo *philo, t_fork *left_fork, t_fork *right_fork)
{
	if (!philo_take_fork(philo, left_fork, right_fork))
		return (FALSE);
	if (philo_print(philo, "is eating") == ERR)
		return (FALSE);
	philo_wait(philo->info->time_to_eat);
	if (!philo_update_time_of_eat(philo, get_time() + philo->info->time_to_eat))
		return (FALSE);
	if (!philo_update_num_of_eat(philo))
		return (FALSE);
	left_fork->fork = FALSE;
	if (pthread_mutex_unlock(&left_fork->mutex))
		return (FALSE);
	right_fork->fork = FALSE;
	if (pthread_mutex_unlock(&right_fork->mutex))
		return (FALSE);
	return (TRUE);
}

t_bool	philo_eat_even(t_philo *philo, t_fork *right_fork, t_fork *left_fork)
{
	if (!philo_take_fork(philo, right_fork, left_fork))
		return (FALSE);
	if (philo_print(philo, "is eating") == ERR)
		return (FALSE);
	philo_wait(philo->info->time_to_eat);
	if (!philo_update_time_of_eat(philo, get_time() + philo->info->time_to_eat))
		return (FALSE);
	if (!philo_update_num_of_eat(philo))
		return (FALSE);
	right_fork->fork = FALSE;
	if (pthread_mutex_unlock(&right_fork->mutex))
		return (FALSE);
	left_fork->fork = FALSE;
	if (pthread_mutex_unlock(&left_fork->mutex))
		return (FALSE);
	return (TRUE);
}