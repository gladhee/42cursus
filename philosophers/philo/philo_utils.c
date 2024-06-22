#include "philo.h"

t_time	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == ERR)
		return (ERR);
	return ((t_time)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

t_time	philo_print(t_philo *philo, char *str)
{
	t_time	time;

	if (is_dead(philo->info))
		return (ERR);
	if (pthread_mutex_lock(&philo->info->print))
		return (ERR);
	time = get_time();
	if (time == ERR || is_dead(philo->info))
	{
		pthread_mutex_unlock(&philo->info->print);
		return (ERR);
	}
	printf("%lld %d %s\n", time - philo->info->start_time, philo->id, str);
	if (pthread_mutex_unlock(&philo->info->print))
		return (ERR);
	return (time);
}
