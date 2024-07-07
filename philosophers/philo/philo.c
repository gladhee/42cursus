#include "philo.h"

int	error_return(void)
{
	write(2, "Error\n", 6);
	return (EXIT_FAILURE);
}

t_bool	philosopher(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->num_of_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, &philo_thread, &philo[i]))
			return (FALSE);
		i++;
	}
	if (!philo_monitor(info, philo))
		return (FALSE);
	i = 0;
	while (i < philo->info->num_of_philo)
	{
		if (pthread_join(philo[i].thread, NULL))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philo;
	t_bool	res;

	info = init_info(argc, argv);
	if (!info)
		return (error_return());
	philo = init_philo(info);
	if (!philo)
		return (error_return());
	res = philosopher(info, philo);
//	free_philo(philo, philo->info->num_of_philo);
//	free_info(info);
	if (!res)
		return (error_return());
	return (EXIT_SUCCESS);
}