#include "philo.h"

t_fork	*init_fork(int philo_num)
{
	t_fork	*forks;
	int		i;

	forks = (t_fork *)malloc(sizeof(t_fork) * philo_num);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < philo_num)
	{
		forks[i].fork = FALSE;
		if (pthread_mutex_init(&forks[i].mutex, NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&forks[i].mutex);
			free(forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

t_info	*init_info(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	memset(info, 0, sizeof(t_info));
	if (!init_arg(info, argc, argv))
	{
		free(info);
		return (NULL);
	}
	info->forks = init_fork(info->num_of_philo);
	if (!info->forks)
	{
		free(info);
		return (NULL);
	}
	if (!init_info_data(info))
	{
		free(info->forks);
		free(info);
		return (NULL);
	}
	return (info);
}

t_bool	init_order(t_info *info)
{
	info->order.data = (int *)malloc(sizeof(int));
	if (!info->order.data)
		return (FALSE);
	*(int *)info->order.data = info->num_of_philo - 1;
	if (pthread_mutex_init(&info->order.mutex, NULL))
	{
		free(info->order.data);
		return (FALSE);
	}
	return (TRUE);
}

t_philo *philo_while(t_info *info, t_mutex *time, t_mutex *num)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (!philo)
		return (NULL);
	while (i < info->num_of_philo)
	{
		init_philo_set(&philo[i], info, i);
		if (!init_philo_data(&philo[i], time, num))
		{
			error_free(info, philo, i);
			return (NULL);
		}
		i++;
	}
	return (philo);
}

t_philo	*init_philo(t_info *info)
{
	t_philo	*philo;
	t_mutex time;
	t_mutex num;

	if (pthread_mutex_init(&time, NULL))
		return (NULL);
	if (pthread_mutex_init(&num, NULL))
	{
		pthread_mutex_destroy(&time);
		return (NULL);
	}
	philo = philo_while(info, &time, &num);
	if (!philo)
		return (NULL);

	return (philo);
}
