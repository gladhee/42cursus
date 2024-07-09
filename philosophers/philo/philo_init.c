/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:17:11 by heechoi           #+#    #+#             */
/*   Updated: 2024/07/09 13:14:23 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	init_order(t_info *info)
{
	info->order.data = (int *)malloc(sizeof(int));
	if (!info->order.data)
		return (FALSE);
	*(int *)info->order.data = 1;
	if (pthread_mutex_init(&info->order.mutex, NULL))
	{
		free(info->order.data);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	init_philo_data(t_philo *philo)
{
	if (pthread_mutex_init(&philo->time_of_eat.mutex, NULL))
		return (FALSE);
	philo->time_of_eat.data = (t_time *)malloc(sizeof(t_time));
	if (!philo->time_of_eat.data)
	{
		pthread_mutex_destroy(&philo->time_of_eat.mutex);
		return (FALSE);
	}
	*(t_time *)philo->time_of_eat.data = philo->info->start_time;
	if (pthread_mutex_init(&philo->num_of_eat.mutex, NULL))
	{
		free(philo->time_of_eat.data);
		pthread_mutex_destroy(&philo->time_of_eat.mutex);
		return (FALSE);
	}
	philo->num_of_eat.data = (int *)malloc(sizeof(int));
	if (!philo->num_of_eat.data)
	{
		pthread_mutex_destroy(&philo->num_of_eat.mutex);
		free(philo->time_of_eat.data);
		pthread_mutex_destroy(&philo->time_of_eat.mutex);
		return (FALSE);
	}
	*(int *)philo->num_of_eat.data = 0;
	return (TRUE);
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
		philo[i].info = info;
		philo[i].id = i + 1;
		philo[i].left_fork = &info->forks[i];
		philo[i].right_fork = &info->forks[(i + 1) % info->num_of_philo];
		if (!init_philo_data(&philo[i]))
		{
			while (--i >= 0)
				destroy_philo_data(&philo[i]);
			free(philo);
			return (NULL);
		}
		i++;
	}
	return (philo);
}
