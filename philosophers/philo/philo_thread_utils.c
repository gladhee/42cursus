#include "philo.h"

t_bool	philo_update_time_of_eat(t_philo *philo, t_time time)
{
	if (pthread_mutex_lock(&philo->time_of_eat.mutex))
		return (FALSE);
	*(t_time *)philo->time_of_eat.data = time;
	if (pthread_mutex_unlock(&philo->time_of_eat.mutex))
		return (FALSE);
	return (TRUE);
}

t_bool	philo_update_num_of_eat(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->num_of_eat.mutex))
		return (FALSE);
	(*(int *)philo->num_of_eat.data)++;
	if (pthread_mutex_unlock(&philo->num_of_eat.mutex))
		return (FALSE);
	return (TRUE);
}

t_bool	pick_up_fork(t_philo *philo, t_fork *fork)
{
	while (TRUE)
	{
		if (pthread_mutex_lock(&fork->mutex))
			return (FALSE);
		if (*fork->is_used == FALSE)
		{
			*fork->is_used = TRUE;
			if (pthread_mutex_unlock(&fork->mutex))
				return (FALSE);
			philo_print(philo, "has taken a fork");
			return (TRUE);
		}
		if (pthread_mutex_unlock(&fork->mutex))
			return (FALSE);
		usleep(100);
	}
}

t_bool	put_down_fork(t_fork *fork)
{
	if (pthread_mutex_lock(&fork->mutex))
		return (FALSE);
	*fork->is_used = FALSE;
	if (pthread_mutex_unlock(&fork->mutex))
		return (FALSE);
	return (TRUE);
}

t_bool	philo_eat(t_philo *philo, t_fork *fork1, t_fork *fork2)
{
	t_time	time;

	if (!pick_up_fork(philo, fork1))
		return (FALSE);
	if (!pick_up_fork(philo, fork2))
		return (FALSE);
	time = philo_print(philo, "is eating");
	if (!philo_update_time_of_eat(philo, time))
		return (FALSE);
	if (!philo_update_num_of_eat(philo))
		return (FALSE);
	msleep(philo->info->time_to_eat);
	if (!put_down_fork(fork1))
		return (FALSE);
	if (!put_down_fork(fork2))
		return (FALSE);
	return (TRUE);
}