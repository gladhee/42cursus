/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:49:24 by heechoi           #+#    #+#             */
/*   Updated: 2024/07/10 19:49:26 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_sleep(t_philo *philo)
{
	philo_print(philo, "is sleeping\n");
	wait_time(philo->info->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	philo_print(philo, "is thinking\n");
	usleep(100);
}

void	philo_process(t_philo *philo)
{
	if (pthread_create(&philo->thread, NULL, &philo_monitor, philo))
		exit_error("Error: pthread_create\n");
	if (pthread_detach(philo->thread))
		exit_error("Error: pthread_detach\n");
	if (philo->id > philo->info->num_of_philo / 2)
		philo_think(philo);
	while (TRUE)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}
