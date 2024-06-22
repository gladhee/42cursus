#include "philo_bonus.h"

void	exit_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	philosopher(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid < 0)
			exit_error();
		if (philo[i].pid == 0)
		{
			philo_process(&philo[i]);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	philo_monitor(info, philo);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philo;

	info = init_info(argc, argv);
	philo = init_philo(info);
	philosopher(info, philo);
	free_philo(philo, info->num_of_philo);
	free_info(info);
	return (EXIT_SUCCESS);
}