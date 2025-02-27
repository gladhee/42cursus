/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:17:15 by heechoi           #+#    #+#             */
/*   Updated: 2024/07/09 12:41:05 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time	get_last_eat(t_philo *philo)
{
	t_time	res;

	if (pthread_mutex_lock(&philo->time_of_eat.mutex))
		return (ERROR);
	res = *((t_time *)philo->time_of_eat.data);
	if (pthread_mutex_unlock(&philo->time_of_eat.mutex))
		return (ERROR);
	return (res);
}

int	get_num_of_eat(t_philo *philo)
{
	int	res;

	if (pthread_mutex_lock(&philo->num_of_eat.mutex))
		return (ERROR);
	res = *((int *)philo->num_of_eat.data);
	if (pthread_mutex_unlock(&philo->num_of_eat.mutex))
		return (ERROR);
	return (res);
}

t_bool	philo_check_dead(t_info *info, t_philo *philo)
{
	t_time	time;
	t_time	now;

	if (is_dead(info))
		return (TRUE);
	time = get_last_eat(philo);
	now = get_time();
	if (now == ERROR || time == ERROR)
		return (FALSE);
	if ((now - time) > (info->time_to_die))
		return (TRUE);
	return (FALSE);
}

t_bool	philo_is_full(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	if (info->num_of_must_eat == -1)
		return (FALSE);
	while (i < info->num_of_philo)
	{
		if (get_num_of_eat(philo) >= info->num_of_must_eat)
			info->eat_cnt++;
		if (info->eat_cnt >= info->num_of_philo)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool	philo_monitor(t_info *info, t_philo *philo)
{
	int		i;
	t_bool	flag;

	flag = TRUE;
	while (flag)
	{
		i = -1;
		while (flag && ++i < info->num_of_philo)
		{
			if (philo_check_dead(info, &philo[i]))
			{
				philo_print(&philo[i], "died");
				set_dead(info);
				flag = FALSE;
			}
			if (philo_is_full(info, philo))
			{
				set_dead(info);
				flag = FALSE;
			}
		}
		usleep(100);
	}
	return (TRUE);
}
