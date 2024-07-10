/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:49:33 by heechoi           #+#    #+#             */
/*   Updated: 2024/07/10 19:49:33 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	exit_error(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

t_time	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == ERROR)
		return (ERROR);
	return ((t_time)time.tv_sec * 1000 + (t_time)time.tv_usec / 1000);
}

t_bool	wait_time(t_time time)
{
	t_time	start_time;
	t_time	now;

	if (time < 10)
		time = 1;
	start_time = get_time();
	if (start_time == ERROR)
		return (FALSE);
	usleep(time * 800);
	while (TRUE)
	{
		now = get_time();
		if (now == ERROR)
			return (FALSE);
		if (now - start_time >= time)
			break ;
		usleep((time - (now - start_time)) * 500);
	}
	return (TRUE);
}

t_time	philo_print(t_philo *philo, char *str)
{
	t_time	time;

	if (sem_wait(philo->info->print))
		return (ERROR);
	if (is_dead(philo->info))
	{
		sem_post(philo->info->print);
		return (ERROR);
	}
	time = get_time();
	if (time == ERROR)
	{
		sem_post(philo->info->print);
		return (ERROR);
	}
	ft_putnbr_fd(time - philo->info->start_time, STDOUT_FILENO);
	write(STDOUT_FILENO, " ", 1);
	ft_putnbr_fd(philo->id, STDOUT_FILENO);
	write(STDOUT_FILENO, " ", 1);
	write(STDOUT_FILENO, str, ft_strlen(str));
	if (sem_post(philo->info->print))
		return (ERROR);
	return (time);
}

char	*sem_name_philo(int id, char *str)
{
	char	*res;
	char	*id_str;

	id_str = ft_itoa(id);
	if (!id_str)
		exit_error("Error: itoa\n");
	res = ft_strjoin(str, id_str);
	if (!res)
		exit_error("Error: ft_strjoin\n");
	free(id_str);
	return (res);
}
