/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:50:23 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/12 19:36:17 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	check_overflow(unsigned long long result, int sign)
{
	if (result > 2147483647 && sign == 1)
		my_error();
	else if (result > 2147483648 && sign == -1)
		my_error();
	return ((int)result * sign);
}

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					sign;
	int					i;

	result = 0;
	sign = 1;
	i = 0;
	if (!str[0])
		my_error();
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!str[i])
		my_error();
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	if (str[i] != '\0')
		my_error();
	return (check_overflow(result, sign));
}
