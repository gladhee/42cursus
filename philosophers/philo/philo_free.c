/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:17:04 by heechoi           #+#    #+#             */
/*   Updated: 2024/07/09 12:17:05 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_forks(t_fork *forks, int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		pthread_mutex_destroy(&forks[i].mutex);
		free(forks[i].is_used);
		i++;
	}
	free(forks);
}

void	destroy_philo_data(t_philo *philo)
{
	pthread_mutex_destroy(&philo->time_of_eat.mutex);
	free(philo->time_of_eat.data);
	pthread_mutex_destroy(&philo->num_of_eat.mutex);
	free(philo->num_of_eat.data);
}

void	free_philo(t_philo *philo, int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		destroy_philo_data(&philo[i]);
		i++;
	}
	free(philo);
}

void	free_info(t_info *info)
{
	destroy_forks(info->forks, info->num_of_philo);
	pthread_mutex_destroy(&info->print);
	free(info->dead.data);
	pthread_mutex_destroy(&info->dead.mutex);
	free(info->order.data);
	pthread_mutex_destroy(&info->order.mutex);
	free(info);
}
