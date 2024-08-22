/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:50:23 by heechoi           #+#    #+#             */
/*   Updated: 2023/10/30 10:11:55 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_legnthcheck(unsigned long long result)
{
	int	len;

	len = 0;
	while (result)
	{
		len++;
		result /= 10;
	}
	if (len > 19)
		return (0);
	return (1);
}

static int	ft_longcheck(unsigned long long result, int sign)
{
	unsigned long long	max;
	int					lencheck;

	max = 9223372036854775807;
	lencheck = ft_legnthcheck(result);
	if ((!lencheck && sign > 0) || (result > max && sign > 0))
		return (-1);
	else if ((!lencheck && sign < 0) || (result > max && sign < 0))
		return (0);
	else
		return (sign * (int)(result));
}

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					sign;
	size_t				i;

	result = 0;
	sign = 1;
	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (ft_longcheck(result, sign));
}
