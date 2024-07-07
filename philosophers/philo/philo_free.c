#include "philo.h"

void	destroy_forks(t_fork *forks, int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		pthread_mutex_destroy(&forks[i].mutex);
		free(forks[i].is_used);
		i++;
	}
	free(forks);
}

void	destroy_philo_data(t_philo *philo)
{
	pthread_mutex_destroy(&philo->time_of_eat.mutex);
	free(philo->time_of_eat.data);
	pthread_mutex_destroy(&philo->num_of_eat.mutex);
	free(philo->num_of_eat.data);
}