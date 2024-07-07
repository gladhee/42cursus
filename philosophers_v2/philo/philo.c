#include "philo.h"

t_bool	exit_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (EXIT_FAILURE);
}

t_bool	philosopher(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, &philo_thread, &philo[i]))
			return (FALSE);
		i++;
	}
	if (!philo_monitor(info, philo))
		return (FALSE);
	i = 0;
	while (i < info->num_of_philo)
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
		return (exit_error());
	init_order(info);
	philo = init_philo(info);
	if (!philo)
		return (exit_error());
	res = philosopher(info, philo);
	free_philo(philo, philo->info->num_of_philo);
	free_info(info);
	if (!res)
		return (exit_error());
	return (EXIT_SUCCESS);
}

// if (life_time - eat_time - sleep - 100 < 10)
// 	  이런 경우는 생각하는 시간이 이걸로