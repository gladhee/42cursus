#include "philo.h"

t_time	get_time_of_eat(t_philo *philo)
{
	t_time	ret;

	if (pthread_mutex_lock(&philo->time_of_eat.mutex))
		return (ERROR);
	ret = *(t_time *)philo->time_of_eat.data;
	if (pthread_mutex_unlock(&philo->time_of_eat.mutex))
		return (ERROR);
	return (ret);
}

int	get_num_of_eat(t_philo *philo)
{
	int	ret;

	if (pthread_mutex_lock(&philo->num_of_eat.mutex))
		return (ERROR);
	ret = *(int *)philo->num_of_eat.data;
	if (pthread_mutex_unlock(&philo->num_of_eat.mutex))
		return (ERROR);
	return (ret);
}

t_bool	philo_check_starvation(t_info *info, t_philo *philo)
{
	t_time	time_of_eat;

	time_of_eat = get_time_of_eat(philo);
	if (get_time() - time_of_eat >= info->time_to_die)
		return (TRUE);
	return (FALSE);
}

t_bool	philo_check_is_full(t_info *info, t_philo *philo)
{
	if (info->num_of_must_eat != -1)
	{
		if (get_num_of_eat(philo) >= info->num_of_must_eat)
			return (TRUE);
	}
	return (FALSE);
}



t_bool	monitor(t_philo *philo, t_info *info, t_bool *flag, int *eaten_count)
{
	t_time	current;

	current = get_time();
	if (current == ERROR)
		return (FALSE);
	if (philo_check_starvation(info, philo))
	{
		philo_print(philo, "died");
		*flag = TRUE;
	}
	if (info->num_of_must_eat != ERROR
		&& get_num_of_eat(philo) >= info->num_of_must_eat)
		(*eaten_count)++;
	return (TRUE);
}

t_bool	philo_monitor(t_info *info, t_philo *philo)
{
	int		i;
	t_bool	flag;
	int		eaten_count;

	flag = FALSE;
	while (!flag)
	{
		i = 0;
		eaten_count = 0;
		while (!flag && i < info->num_of_philo)
		{
			if (!monitor(&philo[i++], info, &flag, &eaten_count))
				return (FALSE);
		}
		if (eaten_count >= info->num_of_philo)
		{
			flag = TRUE;
			set_dead(info);
		}
		usleep(100);
	}
	return (TRUE);
}