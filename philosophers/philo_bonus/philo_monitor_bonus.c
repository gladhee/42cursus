/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:49:22 by heechoi           #+#    #+#             */
/*   Updated: 2024/07/10 19:49:50 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_time	get_last_eat(t_philo *philo)
{
	t_time	res;

	if (sem_wait(philo->time_of_eat.sem))
		exit_error("Error: sem_wait\n");
	res = *(t_time *)philo->time_of_eat.data;
	if (sem_post(philo->time_of_eat.sem))
		exit_error("Error: sem_post\n");
	return (res);
}

int	get_num_of_eat(t_philo *philo)
{
	int	res;

	if (sem_wait(philo->num_of_eat.sem))
		exit_error("Error: sem_wait\n");
	res = *(int *)philo->num_of_eat.data;
	if (sem_post(philo->num_of_eat.sem))
		exit_error("Error: sem_post\n");
	return (res);
}

t_bool	is_starving(t_philo *philo)
{
	t_time	now;

	now = get_time();
	if (now - get_last_eat(philo) > philo->info->time_to_die)
		return (TRUE);
	return (FALSE);
}

t_bool	is_full(t_philo *philo)
{
	if (philo->info->num_of_must_eat != -1 && \
			get_num_of_eat(philo) >= philo->info->num_of_must_eat)
		return (TRUE);
	return (FALSE);
}

void	*philo_monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (is_starving(philo))
		{
			philo_print(philo, "died\n");
			sem_wait(philo->info->print);
			exit(EXIT_DIED);
		}
		if (is_full(philo))
		{
			sem_wait(philo->info->print);
			sem_post(philo->info->print);
			exit(EXIT_FULL);
		}
		usleep(100);
	}
	return (NULL);
}
