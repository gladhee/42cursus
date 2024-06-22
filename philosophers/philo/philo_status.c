#include "philo.h"

t_bool	set_dead(t_info *info)
{
	if (pthread_mutex_lock(&info->dead.mutex))
		return (FALSE);
	*((t_bool *)info->dead.data) = TRUE;
	if (pthread_mutex_unlock(&info->dead.mutex))
		return (FALSE);
	return (TRUE);
}

t_bool	is_dead(t_info *info)
{
	t_bool	res;

	pthread_mutex_lock(&info->dead.mutex);
	res = *(t_bool *)info->dead.data;
	if (pthread_mutex_unlock(&info->dead.mutex))
		return (FALSE);
	return (res);
}
