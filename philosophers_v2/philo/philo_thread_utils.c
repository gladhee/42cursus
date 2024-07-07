#include "philo.h"

//t_bool	philo_take_fork(t_philo *philo, t_fork *fork1, t_fork *fork2)
//{
//	if (pthread_mutex_lock(&fork1->mutex))
//		return (FALSE);
//	fork1->fork = TRUE;
//	if (philo_print(philo, "has taken a fork") == ERR)
//	{
//		fork1->fork = FALSE;
//		pthread_mutex_unlock(&fork1->mutex);
//		return (FALSE);
//	}
//	if (pthread_mutex_lock(&fork2->mutex))
//	{
//		fork1->fork = FALSE;
//		pthread_mutex_unlock(&fork1->mutex);
//		return (FALSE);
//	}
//	fork2->fork = TRUE;
//	if (philo_print(philo, "has taken a fork") == ERR)
//	{
//		fork1->fork = FALSE;
//		fork2->fork = FALSE;
//		pthread_mutex_unlock(&fork1->mutex);
//		pthread_mutex_unlock(&fork2->mutex);
//		return (FALSE);
//	}
//	return (TRUE);
//}

//t_bool	philo_take_fork(t_philo *philo, t_fork *fork1, t_fork *fork2)
//{
//
//}

t_bool	philo_update_time_of_eat(t_philo *philo, t_time time)
{
	if (pthread_mutex_lock(&philo->time_of_eat.mutex))
		return (FALSE);
	*((t_time *)philo->time_of_eat.data) = time;
	if (pthread_mutex_unlock(&philo->time_of_eat.mutex))
		return (FALSE);
	return (TRUE);
}

t_bool	philo_update_num_of_eat(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->num_of_eat.mutex))
		return (FALSE);
	*((int *)philo->num_of_eat.data) += 1;
	if (pthread_mutex_unlock(&philo->num_of_eat.mutex))
		return (FALSE);
	return (TRUE);
}

//int pick_up_fork()
//{
//	while (TRUE)
//	{
//		pthread_mutex_lock(&mutex);
//		if (is_occupied == FALSE && recent_user != number)
//		{
//			is_occupied = TRUE;
//			recent_user = number;
//			pthread_mutex_unlock(&mutex);
//			break ;
//		}
//		pthread_mutex_unlock(&mutex);
//		usleep(500);
//	}
//	return (EXIT_SUCCESS);
//}

t_bool	pick_up_fork(t_philo *philo, t_fork *fork)
{
	while (TRUE)
	{
		pthread_mutex_lock(&fork->mutex);
		if (fork->fork == FALSE)
		{
			fork->fork = TRUE;
			pthread_mutex_unlock(&fork->mutex);
			philo_print(philo, "has taken a fork");
			break ;
		}
		pthread_mutex_unlock(&fork->mutex);
		usleep(100);
	}
	return (TRUE);
}

t_bool	philo_eat(t_philo *philo, t_fork *fork1, t_fork *fork2)
{
	while (pick_up_fork(philo, fork1))
	{
		while (pick_up_fork(philo, fork2))
		{
			t_time	time;

			time = philo_print(philo, "is eating");
			if (time == ERR)
			{
				fork1->fork = FALSE;
				pthread_mutex_unlock(&fork1->mutex);
				fork2->fork = FALSE;
				pthread_mutex_unlock(&fork2->mutex);
				return (FALSE);
			}
			philo_update_time_of_eat(philo, time);
			philo_wait(philo->info->time_to_eat);
			philo_update_num_of_eat(philo);
			pthread_mutex_lock(&fork1->mutex);
			fork1->fork = FALSE;
			pthread_mutex_unlock(&fork1->mutex);
			pthread_mutex_lock(&fork2->mutex);
			fork2->fork = FALSE;
			pthread_mutex_unlock(&fork2->mutex);
			return (TRUE);
		}
	}
	return (FALSE);
}

//t_bool	philo_eat(t_philo *philo, t_fork *fork1, t_fork *fork2)
//{
//	t_time	time;
//
//	if (!philo_take_fork(philo, fork1, fork2))
//		return (FALSE);
//	time = philo_print(philo, "is eating");
//	if (time == ERR)
//	{
//		fork1->fork = FALSE;
//		pthread_mutex_unlock(&fork1->mutex);
//		fork2->fork = FALSE;
//		pthread_mutex_unlock(&fork2->mutex);
//		return (FALSE);
//	}
//	philo_update_time_of_eat(philo, time);
//	philo_wait(philo->info->time_to_eat);
//	philo_update_num_of_eat(philo);
//	fork1->fork = FALSE;
//	pthread_mutex_unlock(&fork1->mutex);
//	fork2->fork = FALSE;
//	pthread_mutex_unlock(&fork2->mutex);
//	return (TRUE);
//}