#include "philo.h"

int	get_last_eat(t_philo *philo)
{
	int	res;

	if (pthread_mutex_lock(&philo->time_of_eat.mutex))
		return (ERR);
	res = *((int *)philo->time_of_eat.data);
	if (pthread_mutex_unlock(&philo->time_of_eat.mutex))
		return (ERR);
	return (res);
}

int	get_num_of_eat(t_philo *philo)
{
	int	res;

	if (pthread_mutex_lock(&philo->num_of_eat.mutex))
		return (ERR);
	res = *((int *)philo->num_of_eat.data);
	if (pthread_mutex_unlock(&philo->num_of_eat.mutex))
		return (ERR);
	return (res);
}

t_bool	philo_check_dead(t_info *info, t_philo *philo)
{
	t_time	time;

	if (is_dead(info))
		return (TRUE);
	if (pthread_mutex_lock(&philo->time_of_eat.mutex))
		return (FALSE);
	time = *((t_time *)philo->time_of_eat.data);
	if (pthread_mutex_unlock(&philo->time_of_eat.mutex))
		return (FALSE);
	if (get_time() - time >= info->time_to_die)
		return (TRUE);
	return (FALSE);
}

t_bool	philo_check_starvation(t_info *info, t_philo *philo)
{
	if (info->num_of_must_eat != -1)
	{
		if (get_num_of_eat(philo) > info->num_of_must_eat)
			return (TRUE);
	}
	return (FALSE);
}

t_bool	philo_monitor(t_info *info, t_philo *philo)
{
	int		i;
	t_bool	flag;

	flag = TRUE;
	while (flag)
	{
		i = 0;
		while (i < info->num_of_philo)
		{
			if (philo_check_dead(info, &philo[i]))
			{
				philo_print(&philo[i], "died");
				set_dead(info);
				flag = FALSE;
			}
			if (philo_check_starvation(info, &philo[i]))
			{
				set_dead(info);
				flag = FALSE;
			}
			i++;
		}
		usleep(100);
	}
	return (TRUE);
}