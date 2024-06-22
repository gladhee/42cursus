#include "philo.h"

t_bool	philo_wait(t_time set)
{
	t_time	start;
	t_time	time;

	start = get_time();
	if (start == ERR)
		return (FALSE);
	time = start;
	while (set > time - start)
	{
		usleep(100);
		time = get_time();
		if (time == ERR)
			return (FALSE);
	}
	return (TRUE);
}

//t_bool	philo_wait(t_time set)
//{
//	t_time   begin_time;
//
//	begin_time = get_time();
//	while (begin_time + set - get_time() > 1)
//		usleep((begin_time + set - get_time()) * 0.5 * 1000);
//	while (begin_time + set > get_time())
//		usleep(100);
//	return (TRUE);
//}

t_bool	philo_think(t_philo *philo)
{
	if (!philo_print(philo, "is thinking"))
		return (FALSE);
	return (TRUE);
}

t_bool	philo_sleep(t_philo *philo)
{
	if (!philo_print(philo, "is sleeping"))
		return (FALSE);
	if (!philo_wait(philo->info->time_to_sleep))
		return (FALSE);
	return (TRUE);
}

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id & 1)
		usleep(100);
	while (!is_dead(philo->info))
	{
		if (!philo_think(philo))
			break ;
		if (~philo->id & 1)
		{
			if (!philo->eat(philo, philo->right_fork, philo->left_fork))
				break ;
		}
		else
		{
			if (!philo->eat(philo, philo->left_fork, philo->right_fork))
				break ;
		}
		if (!philo_sleep(philo))
			break ;
	}
	set_dead(philo->info);
	return (NULL);
}

