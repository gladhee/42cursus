/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:17:00 by heechoi           #+#    #+#             */
/*   Updated: 2024/07/09 12:38:58 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time	philo_update_time_of_eat(t_philo *philo, t_time time)
{
	if (pthread_mutex_lock(&philo->time_of_eat.mutex))
		return (FALSE);
	*(t_time *)philo->time_of_eat.data = time;
	if (pthread_mutex_unlock(&philo->time_of_eat.mutex))
		return (FALSE);
	return (time);
}

t_bool	philo_update_num_of_eat(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->num_of_eat.mutex))
		return (FALSE);
	(*(int *)philo->num_of_eat.data)++;
	if (pthread_mutex_unlock(&philo->num_of_eat.mutex))
		return (FALSE);
	return (TRUE);
}

t_bool	pick_up_fork(t_philo *philo, t_fork *fork)
{
	while (TRUE)
	{
		if (is_dead(philo->info))
			return (FALSE);
		if (pthread_mutex_lock(&fork->mutex))
			return (FALSE);
		if (*fork->is_used == FALSE)
		{
			*fork->is_used = TRUE;
			philo_print(philo, "has taken a fork");
			pthread_mutex_unlock(&fork->mutex);
			return (TRUE);
		}
		pthread_mutex_unlock(&fork->mutex);
		if (philo->info->num_of_philo == 1)
		{
			while (!is_dead(philo->info))
				usleep(100);
			return (FALSE);
		}
		usleep(100);
	}
}

t_bool	put_down_fork(t_fork *fork)
{
	while (TRUE)
	{
		if (pthread_mutex_lock(&fork->mutex))
			return (FALSE);
		if (*fork->is_used == TRUE)
		{
			*fork->is_used = FALSE;
			pthread_mutex_unlock(&fork->mutex);
			return (TRUE);
		}
		pthread_mutex_unlock(&fork->mutex);
		usleep(100);
	}
}

t_bool	philo_eat(t_philo *philo, t_fork *fork1, t_fork *fork2)
{
	t_time	time;

	if (!pick_up_fork(philo, fork1))
		return (FALSE);
	if (!pick_up_fork(philo, fork2))
	{
		put_down_fork(fork1);
		return (FALSE);
	}
	time = philo_print(philo, "is eating");
	if (time == ERROR)
		return (FALSE);
	philo_update_time_of_eat(philo, time);
	wait_time(philo->info->time_to_eat);
	philo_update_num_of_eat(philo);
	if (!put_down_fork(fork1))
	{
		put_down_fork(fork2);
		return (FALSE);
	}
	if (!put_down_fork(fork2))
		return (FALSE);
	return (TRUE);
}
