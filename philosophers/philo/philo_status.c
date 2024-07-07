#include "philo.h"

t_bool	set_dead(t_info *info)
{
	if (pthread_mutex_lock(&info->dead.mutex))
		return (FALSE);
	*(t_bool *)info->dead.data = TRUE;
	pthread_mutex_unlock(&info->dead.mutex);
	return (TRUE);
}

t_bool	is_dead(t_info *info)
{
	t_bool	ret;

	if (pthread_mutex_lock(&info->dead.mutex))
		return (FALSE);
	ret = *(t_bool *)info->dead.data;
	pthread_mutex_unlock(&info->dead.mutex);
	return (ret);
}

int get_order(t_info *info)
{
	int	ret;

	if (pthread_mutex_lock(&info->order.mutex))
		return (ERROR);
	ret = *(int *)info->order.data;
	pthread_mutex_unlock(&info->order.mutex);
	return (ret);
}

t_bool	next_order(t_info *info)
{
	if (pthread_mutex_lock(&info->order.mutex))
		return (FALSE);
	(*(int *)info->order.data)++;
	if (*(int *)info->order.data == info->num_of_philo + 1)
		(*(int *)info->order.data) = 1;
	pthread_mutex_unlock(&info->order.mutex);
	return (TRUE);
}