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

void	error_free(t_info *info, t_philo *philo, int i)
{
	while (--i >= 0)
	{
		pthread_mutex_destroy(&philo[i].time_of_eat.mutex);
		pthread_mutex_destroy(&philo[i].num_of_eat.mutex);
		free(philo[i].time_of_eat.data);
		free(philo[i].num_of_eat.data);
	}
	free(philo);
	free_info(info);
}

t_philo	*init_philo(t_info *info)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < info->num_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].info = info;
		philo[i].left_fork = &info->forks[i];
		philo[i].right_fork = &info->forks[(i + 1) % info->num_of_philo];
		if ((i + 1) % 2 == 0)
			philo[i].eat = philo_eat_even;
		else
			philo[i].eat = philo_eat_odd;
		if (!init_philo_data(&philo[i]))
		{
			error_free(info, philo, i);
			return (NULL);
		}
		i++;
	}
	return (philo);
}
