#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(nbr * sign));
}

t_bool	init_arg(t_info *info, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (FALSE);
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->num_of_must_eat = ft_atoi(argv[5]);
	else
		info->num_of_must_eat = -1;
	if (info->num_of_philo < 2 || info->time_to_die < 0
		|| info->time_to_eat < 0 || info->time_to_sleep < 0
		|| (argc == 6 && info->num_of_must_eat < 1))
		return (FALSE);
	info->start_time = get_time();
	if (!init_order(info))
		return (FALSE);
	return (TRUE);
}

t_bool	init_info_data(t_info *info)
{
	if (pthread_mutex_init(&info->print, NULL))
		return (FALSE);
	info->dead.data = (t_bool *)malloc(sizeof(t_bool));
	if (!info->dead.data)
	{
		pthread_mutex_destroy(&info->print);
		return (FALSE);
	}
	*(t_bool *)info->dead.data = FALSE;
	if (pthread_mutex_init(&info->dead.mutex, NULL))
	{
		free(info->dead.data);
		pthread_mutex_destroy(&info->print);
		return (FALSE);
	}
	return (TRUE);
}

void	init_philo_set(t_philo *philo, t_info *info, int i)
{
	philo->info = info;
	philo->id = i;
	philo->left_fork = &info->forks[i];
	philo->right_fork = &info->forks[(i + 1) % info->num_of_philo];
	philo->eat = philo_eat;
}

t_bool	init_philo_data(t_philo *philo, t_mutex *time, t_mutex *num)
{
	philo->time_of_eat.data = (t_time *)malloc(sizeof(t_time));
	if (!philo->time_of_eat.data)
		return (FALSE);
	*(t_time *)philo->time_of_eat.data = philo->info->start_time;
	philo->time_of_eat.mutex = *time;
	philo->num_of_eat.data = (int *)malloc(sizeof(int));
	if (!philo->num_of_eat.data)
	{
		free(philo->time_of_eat.data);
		return (FALSE);
	}
	*(int *)philo->num_of_eat.data = 0;
	philo->num_of_eat.mutex = *num;
	return (TRUE);
}
