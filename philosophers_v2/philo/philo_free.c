#include "philo.h"

void	destroy_fork(t_fork *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_destroy(&forks[i].mutex);
		i++;
	}
	free(forks);
}

void	free_info(t_info *info)
{
	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->dead.mutex);
	free(info->dead.data);
	destroy_fork(info->forks, info->num_of_philo);
	free(info);
}

void	free_philo(t_philo *philo, int philo_num)
{
	int	i;

	pthread_mutex_destroy(&philo->time_of_eat.mutex);
	pthread_mutex_destroy(&philo->num_of_eat.mutex);
	i = 0;
	while (i < philo_num)
	{
		free(philo[i].time_of_eat.data);
		free(philo[i].num_of_eat.data);
		i++;
	}
	free(philo);
}

void	error_free(t_info *info, t_philo *philo, int i)
{
	pthread_mutex_destroy(&philo->time_of_eat.mutex);
	pthread_mutex_destroy(&philo->num_of_eat.mutex);
	while (--i >= 0)
	{
		free(philo[i].time_of_eat.data);
		free(philo[i].num_of_eat.data);
	}
	free(philo);
	free_info(info);
}