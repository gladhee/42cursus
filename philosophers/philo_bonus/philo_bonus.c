/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:49:01 by heechoi           #+#    #+#             */
/*   Updated: 2024/07/10 19:50:33 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_process(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->num_of_philo)
	{
		kill(philo[i].pid, SIGKILL);
		i++;
	}
}

int	exit_status(int status)
{
	return (((status) >> 8) & 0xff);
}

void	wait_process(t_info *info, t_philo *philo)
{
	int	i;
	int	status;
	int	eat_num;

	eat_num = 0;
	i = 0;
	while (i < info->num_of_philo)
	{
		waitpid(-1, &status, 0);
		if (exit_status(status) == EXIT_FULL)
			eat_num++;
		if (exit_status(status) == EXIT_DIED
			|| exit_status(status) == EXIT_FAILURE)
		{
			kill_process(philo);
			return ;
		}
		i++;
	}
	if (eat_num >= info->num_of_philo)
	{
		kill_process(philo);
		return ;
	}
}

t_bool	philosopher(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid < 0)
		{
			while (--i >= 0)
				kill(philo[i].pid, SIGKILL);
			exit_error("Error: fork\n");
		}
		if (philo[i].pid == 0)
		{
			philo_process(&philo[i]);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	wait_process(info, philo);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philo;

	info = init_info(argc, argv);
	philo = init_philo(info);
	philosopher(info, philo);
	free_philo(philo, philo->info->num_of_philo);
	free_info(info);
	return (EXIT_SUCCESS);
}
