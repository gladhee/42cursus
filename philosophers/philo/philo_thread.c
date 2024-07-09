/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:16:56 by heechoi           #+#    #+#             */
/*   Updated: 2024/07/09 12:33:09 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	philo_sleep_think(t_philo *philo)
{
	if (philo_print(philo, "is sleeping") == ERROR)
		return (FALSE);
	wait_time(philo->info->time_to_sleep);
	if (philo_print(philo, "is thinking") == ERROR)
		return (FALSE);
	if ((philo->info->num_of_philo & 1) && philo->id == get_order(philo->info))
	{
		next_order(philo->info);
		wait_time(philo->info->time_to_eat);
	}
	else
		usleep(100);
	return (TRUE);
}

t_bool	philo_think(t_philo *philo)
{
	if (philo_print(philo, "is thinking") == ERROR)
		return (FALSE);
	if ((philo->info->num_of_philo & 1) && philo->id == get_order(philo->info))
	{
		next_order(philo->info);
		wait_time(philo->info->time_to_eat);
	}
	else
		usleep(100);
	return (TRUE);
}

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id & 1)
	{
		philo_think(philo);
		wait_time(50);
	}
	while (!is_dead(philo->info))
	{
		if (philo->id & 1)
		{
			if (!philo_eat(philo, philo->left_fork, philo->right_fork))
				break ;
		}
		else
		{
			if (!philo_eat(philo, philo->right_fork, philo->left_fork))
				break ;
		}
		if (!philo_sleep_think(philo))
			break ;
	}
	set_dead(philo->info);
	return (NULL);
}
