/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_info_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:49:19 by heechoi           #+#    #+#             */
/*   Updated: 2024/07/10 19:49:20 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_info_sem(t_info *info)
{
	sem_unlink("forks");
	info->forks = sem_open("forks", O_CREAT, 0644, info->num_of_philo);
	if (info->forks == SEM_FAILED)
		exit_error("Error: sem_open\n");
	sem_unlink("print");
	info->print = sem_open("print", O_CREAT, 0644, 1);
	if (info->print == SEM_FAILED)
		exit_error("Error: sem_open\n");
}

void	init_info_data(t_info *info)
{
	info->dead.data = (t_bool *)malloc(sizeof(t_bool));
	if (!info->dead.data)
		exit_error("Error: malloc\n");
	*(t_bool *)info->dead.data = FALSE;
	sem_unlink("dead");
	info->dead.sem = sem_open("dead", O_CREAT, 0644, 1);
	if (info->dead.sem == SEM_FAILED)
		exit_error("Error: sem_open\n");
}

t_info	*init_info(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		exit_error("Error: malloc\n");
	memset(info, 0, sizeof(t_info));
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
		exit_error("Error: invalid arguments\n");
	info->start_time = get_time();
	init_info_sem(info);
	init_info_data(info);
	return (info);
}
// 세마  포어는 파일로서 존재한다
