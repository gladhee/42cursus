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

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_destroy(&philo[i].time_of_eat.mutex);
		pthread_mutex_destroy(&philo[i].num_of_eat.mutex);
		free(philo[i].time_of_eat.data);
		free(philo[i].num_of_eat.data);
		i++;
	}
	free(philo);
}