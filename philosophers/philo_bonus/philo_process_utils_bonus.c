/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:49:27 by heechoi           #+#    #+#             */
/*   Updated: 2024/07/10 19:49:28 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_bool	philo_update_time_of_eat(t_philo *philo, t_time time)
{
	if (sem_wait(philo->time_of_eat.sem))
		exit_error("Error: sem_wait\n");
	*(t_time *)philo->time_of_eat.data = time;
	if (sem_post(philo->time_of_eat.sem))
		exit_error("Error: sem_post\n");
	return (TRUE);
}

t_bool	philo_update_num_of_eat(t_philo *philo)
{
	if (sem_wait(philo->num_of_eat.sem))
		exit_error("Error: sem_wait\n");
	(*(int *)philo->num_of_eat.data)++;
	if (sem_post(philo->num_of_eat.sem))
		exit_error("Error: sem_post\n");
	return (TRUE);
}

void	philo_eat(t_philo *philo)
{
	t_time	time;

	if (sem_wait(philo->info->forks))
		exit_error("Error: sem_wait\n");
	philo_print(philo, "has taken a fork\n");
	if (sem_wait(philo->info->forks))
		exit_error("Error: sem_wait\n");
	philo_print(philo, "has taken a fork\n");
	time = philo_print(philo, "is eating\n");
	if (time == ERROR)
		exit_error("Error: philo_print\n");
	philo_update_time_of_eat(philo, time);
	wait_time(philo->info->time_to_eat);
	philo_update_num_of_eat(philo);
	if (sem_post(philo->info->forks))
		exit_error("Error: sem_post\n");
	if (sem_post(philo->info->forks))
		exit_error("Error: sem_post\n");
}
