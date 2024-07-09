/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:17:08 by heechoi           #+#    #+#             */
/*   Updated: 2024/07/09 12:39:22 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	init_info_data(t_info *info)
{
	if (pthread_mutex_init(&info->print, NULL))
		return (FALSE);
	info->dead.data = (t_bool *)malloc(sizeof(t_bool));
	if (!info->dead.data)
	{
		pthread_mutex_destroy(&info->print);
		return (FALSE);
	}
	*(t_bool *)info->dead.data = FALSE;
	if (pthread_mutex_init(&info->dead.mutex, NULL))
	{
		free(info->dead.data);
		pthread_mutex_destroy(&info->print);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	init_fork(t_fork *fork)
{
	if (pthread_mutex_init(&fork->mutex, NULL))
		return (FALSE);
	fork->is_used = (t_bool *)malloc(sizeof(t_bool));
	if (!fork->is_used)
	{
		pthread_mutex_destroy(&fork->mutex);
		return (FALSE);
	}
	*fork->is_used = FALSE;
	return (TRUE);
}

t_fork	*init_forks(int num_of_philo)
{
	t_fork	*forks;
	int		i;

	forks = (t_fork *)malloc(sizeof(t_fork) * num_of_philo);
	if (!forks)
		return (FALSE);
	i = 0;
	while (i < num_of_philo)
	{
		if (!init_fork(&forks[i]))
		{
			while (--i >= 0)
			{
				pthread_mutex_destroy(&forks[i].mutex);
				free(forks[i].is_used);
			}
			free(forks);
			return (FALSE);
		}
		i++;
	}
	return (forks);
}

t_bool	init_arg(t_info *info, int argc, char **argv)
{
	if (5 > argc || argc > 6)
		return (FALSE);
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->num_of_must_eat = ft_atoi(argv[5]);
	else
		info->num_of_must_eat = -1;
	if (info->num_of_philo < 1 || info->time_to_die < 0
		|| info->time_to_eat < 0 || info->time_to_sleep < 0
		|| (argc == 6 && info->num_of_must_eat < 1))
		return (FALSE);
	info->start_time = get_time();
	if (info->start_time == ERROR)
		return (FALSE);
	if (!init_order(info))
		return (FALSE);
	return (TRUE);
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
	info->forks = init_forks(info->num_of_philo);
	if (!info->forks)
	{
		free(info);
		return (NULL);
	}
	if (!init_info_data(info))
	{
		destroy_forks(info->forks, info->num_of_philo);
		free(info);
		return (NULL);
	}
	return (info);
}
