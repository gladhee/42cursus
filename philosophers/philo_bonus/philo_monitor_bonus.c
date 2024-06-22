#include "philo_bonus.h"

void	philo_monitor(t_info *info, t_philo *philo)
{
	int		i;
	int		status;
	t_time	time;

	i = 0;
	while (TRUE)
	{
		waitpid(-1, &status, WNOHANG);
		if (WIFEXITED(status) || WIFSIGNALED(status))
			break ;
		time = get_time();
		if (time - philo[i].time_of_eat.data > info->time_to_die)
		{
			sem_wait(&info->print);
			printf("%lld %d died\n", time - info->start_time, philo[i].id);
			sem_post(&info->dead.mutex);
			break ;
		}
		i++;
		if (i == info->num_of_philo)
			i = 0;
	}
}