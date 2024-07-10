/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:49:30 by heechoi           #+#    #+#             */
/*   Updated: 2024/07/10 19:49:31 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_bool	is_dead(t_info *info)
{
	t_bool	ret;

	if (sem_wait(info->dead.sem))
		exit_error("Error: sem_wait");
	ret = *(t_bool *)info->dead.data;
	if (sem_post(info->dead.sem))
		exit_error("Error: sem_post");
	return (ret);
}

t_bool	set_dead(t_info *info)
{
	if (sem_wait(info->dead.sem))
		exit_error("Error: sem_wait");
	*(t_bool *)info->dead.data = TRUE;
	if (sem_post(info->dead.sem))
		exit_error("Error: sem_post");
	return (TRUE);
}
