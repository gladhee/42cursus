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
	if (argc != 5 && argc != 6)
		return (FALSE);
	if (argc == 5)
		info->num_of_must_eat = -1;
	else
		info->num_of_must_eat = ft_atoi(argv[5]);
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (info->num_of_philo < 1 || info->time_to_die < 1 || info->time_to_eat < 1
		|| info->time_to_sleep < 1 || (argc == 6 && info->num_of_must_eat < 1))
		return (FALSE);
	info->start_time = get_time();
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

t_bool	init_philo_data(t_philo *philo)
{
	philo->time_of_eat.data = (t_time *)malloc(sizeof(t_time));
	if (!philo->time_of_eat.data)
		return (FALSE);
	*((t_time *)philo->time_of_eat.data) = philo->info->start_time;
	if (pthread_mutex_init(&philo->time_of_eat.mutex, NULL))
	{
		free(philo->time_of_eat.data);
		return (FALSE);
	}
	philo->num_of_eat.data = (t_time *)malloc(sizeof(t_time));
	if (!philo->num_of_eat.data)
	{
		pthread_mutex_destroy(&philo->time_of_eat.mutex);
		free(philo->time_of_eat.data);
		return (FALSE);
	}
	*((t_time *)philo->num_of_eat.data) = 0;
	if (pthread_mutex_init(&philo->num_of_eat.mutex, NULL))
	{
		free(philo->num_of_eat.data);
		pthread_mutex_destroy(&philo->time_of_eat.mutex);
		free(philo->time_of_eat.data);
		return (FALSE);
	}
	return (TRUE);
}
