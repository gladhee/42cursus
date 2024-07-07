#include "philo.h"

t_time	get_last_eat(t_philo *philo)
{
	t_time	res;

	if (pthread_mutex_lock(&philo->time_of_eat.mutex))
		return (ERR);
	res = *((t_time *)philo->time_of_eat.data);
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
	time = get_last_eat(philo);
	if (get_time() - time >= info->time_to_die)
		return (TRUE);
	return (FALSE);
}

t_bool	philo_is_full(t_info *info, t_philo *philo)
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
		while (flag && i < info->num_of_philo)
		{
			if (philo_check_dead(info, &philo[i]))
			{
				pthread_mutex_lock(&info->print);
				set_dead(info);
				pthread_mutex_unlock(&info->print);
				printf("%lld %d %s\n", get_time() - info->start_time, i + 1, "died");
				flag = FALSE;
			}
			if (philo_is_full(info, &philo[i]))
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
