#include "philo.h"

t_time	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == ERROR)
		return (ERROR);
	return ((t_time)time.tv_sec * 1000 + (t_time)time.tv_usec / 1000);
}

void	msleep(t_time time)
{
	t_time	start_time;
	t_time	now;

	if (time < 10)
		time = 1;
	start_time = get_time();
	if (start_time == ERROR)
		return ;
	usleep(time * 800);
	while (TRUE)
	{
		now = get_time();
		if (now == ERROR)
			return ;
		if (now - start_time >= time)
			break ;
		usleep((time - (now - start_time)) * 500);
	}
}

t_time	philo_print(t_philo *philo, char *str)
{
	t_time	time;

	if (pthread_mutex_lock(&philo->info->print))
		return (ERROR);
	time = get_time();
	if (time == ERROR)
	{
		pthread_mutex_unlock(&philo->info->print);
		return (ERROR);
	}
	printf("%lld %d %s\n", time - philo->info->start_time, philo->id, str);
	if (pthread_mutex_unlock(&philo->info->print))
		return (ERROR);
	return (time);
}

int ft_atoi(const char *str)
{
	unsigned long long	res;
	int					sign;
	int 				i;

	res = 0;
	sign = 1;
	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!str[i])
		return (ERROR);
	while ('0' <= str[i] && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	if (str[i] != '\0')
		return (ERROR);
	if ((res > 2147483647 && sign == 1) || (res > 2147483648 && sign == -1))
		return (ERROR);
	return ((int)res * sign);
}