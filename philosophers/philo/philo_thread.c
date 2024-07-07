#include "philo.h"

t_bool	philo_sleep(t_philo *philo)
{
	if (philo_print(philo, "is sleeping") == ERROR)
		return (FALSE);
	msleep(philo->info->time_to_sleep);
	return (TRUE);
}

t_bool	philo_think(t_philo *philo)
{
	if (philo_print(philo, "is thinking") == ERROR)
		return (FALSE);
	if ((philo->info->num_of_philo & 1) && philo->id == get_order(philo->info))
	{
		next_order(philo->info);
		msleep(philo->info->time_to_eat);
	}
	else
		msleep(100);
	return (TRUE);
}

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id & 1)
		philo_think(philo);
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