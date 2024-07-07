#include "philo.h"

t_bool	set_dead(t_info *info)
{
	if (pthread_mutex_lock(&info->dead.mutex))
		return (FALSE);
	*((t_bool *)(info->dead.data)) = TRUE;
	if (pthread_mutex_unlock(&info->dead.mutex))
		return (FALSE);
	return (TRUE);
}

t_bool	is_dead(t_info *info)
{
	t_bool	res;

	if (pthread_mutex_lock(&info->dead.mutex))
		return (P_ERR);
	res = *((t_bool *)info->dead.data);
	if (pthread_mutex_unlock(&info->dead.mutex))
		return (P_ERR);
	return (res);
}

int	get_late_order(t_info *info)
{
	int	res;

	if (pthread_mutex_lock(&info->order.mutex))
		return (P_ERR);
	res = *(int *)info->order.data;
	if (pthread_mutex_unlock(&info->order.mutex))
		return (P_ERR);
	return (res);
}

t_bool	next_order(t_info *info)
{
	if (pthread_mutex_lock(&info->order.mutex))
		return (FALSE);
	(*(int *)info->order.data) += 1;
	(*(int *)info->order.data) %= info->num_of_philo;
	if (pthread_mutex_unlock(&info->order.mutex))
		return (FALSE);
	return (TRUE);
}