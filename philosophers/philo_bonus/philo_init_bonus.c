/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:49:16 by heechoi           #+#    #+#             */
/*   Updated: 2024/07/10 19:50:26 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_bool	init_philo_data(t_philo *philo, int i)
{
	philo->sem_time = sem_name_philo(i + 1, "time_of_eat");
	if (!philo->sem_time)
		exit_error("Error: sem_name_philo\n");
	philo->sem_num = sem_name_philo(i + 1, "num_of_eat");
	if (!philo->sem_num)
		exit_error("Error: sem_name_philo\n");
	philo->time_of_eat.data = (t_time *)malloc(sizeof(t_time));
	if (!philo->time_of_eat.data)
		exit_error("Error: malloc\n");
	*(t_time *)philo->time_of_eat.data = philo->info->start_time;
	sem_unlink(philo->sem_time);
	philo->time_of_eat.sem = sem_open(philo->sem_time, O_CREAT, 0644, 1);
	if (philo->time_of_eat.sem == SEM_FAILED)
		exit_error("Error: sem_open\n");
	philo->num_of_eat.data = (int *)malloc(sizeof(int));
	if (!philo->num_of_eat.data)
		exit_error("Error: malloc\n");
	*(int *)philo->num_of_eat.data = 0;
	sem_unlink(philo->sem_num);
	philo->num_of_eat.sem = sem_open(philo->sem_num, O_CREAT, 0644, 1);
	if (philo->num_of_eat.sem == SEM_FAILED)
		exit_error("Error: sem_open\n");
	return (TRUE);
}

t_philo	*init_philo(t_info *info)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (!philo)
		exit_error("Error: malloc\n");
	memset(philo, 0, sizeof(t_philo) * info->num_of_philo);
	i = 0;
	while (i < info->num_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].info = info;
		init_philo_data(&philo[i], i);
		i++;
	}
	return (philo);
}
