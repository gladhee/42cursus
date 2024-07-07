#include "philo.h"

// @todo 여기에 데드체크추가
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


t_bool	philo_sleep(t_philo *philo)
{
	if (philo_print(philo, "is sleeping") == ERR)
		return (FALSE);
	if (!philo_wait(philo->info->time_to_sleep))
		return (FALSE);
	return (TRUE);
}

t_bool	philo_think(t_philo *philo)
{
	if (philo_print(philo, "is thinking") == ERR)
		return (FALSE);
	if ((philo->info->num_of_philo & 1) && philo->id == get_late_order(philo->info))
	{
		next_order(philo->info);
		philo_wait(philo->info->time_to_eat);
	}
	else
		usleep(philo->info->time_to_eat / 3);
	return (TRUE);
}

void	*philo_thread(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (~philo->id & 1)
	{
		philo_think(philo);
		philo_wait(100);
	}
	while (TRUE)
	{
		if (philo->id & 1)
		{
			if (!philo->eat(philo, philo->left_fork, philo->right_fork))
				break ;
		}
		else
		{
			if (!philo->eat(philo, philo->right_fork, philo->left_fork))
				break ;
		}
		if (!philo_sleep(philo))
			break ;
		if (!philo_think(philo))
			break ;
	}
	set_dead(philo->info);
	return (NULL);
}
