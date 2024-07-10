/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:49:07 by heechoi           #+#    #+#             */
/*   Updated: 2024/07/10 19:49:08 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_info(t_info *info)
{
	if (sem_close(info->forks))
		exit_error("Error: sem_close\n");
	if (sem_unlink("forks"))
		exit_error("Error: sem_unlink\n");
	if (sem_close(info->dead.sem))
		exit_error("Error: sem_close\n");
	if (sem_unlink("dead"))
		exit_error("Error: sem_unlink\n");
	free(info->dead.data);
	if (sem_close(info->print))
		exit_error("Error: sem_close\n");
	if (sem_unlink("print"))
		exit_error("Error: sem_unlink\n");
	free(info);
}

void	free_philo(t_philo *philo, int num_of_philo)
{
	int		i;

	i = 0;
	while (i < num_of_philo)
	{
		if (sem_close(philo[i].time_of_eat.sem))
			exit_error("Error: sem_close\n");
		if (sem_unlink(philo[i].sem_time))
			exit_error("Error: sem_unlink\n");
		free(philo[i].sem_time);
		if (sem_close(philo[i].num_of_eat.sem))
			exit_error("Error: sem_close\n");
		if (sem_unlink(philo[i].sem_num))
			exit_error("Error: sem_unlink\n");
		free(philo[i].sem_num);
		free(philo[i].time_of_eat.data);
		free(philo[i].num_of_eat.data);
		i++;
	}
	free(philo);
}
