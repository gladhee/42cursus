/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:32:38 by heechoi           #+#    #+#             */
/*   Updated: 2024/05/22 11:48:01 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	is_valid(const char *str)
{
	int	i;
	int	dot_count;
	int	sign_count;

	i = 0;
	dot_count = 0;
	sign_count = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
			dot_count++;
		else if (str[i] == '-' || str[i] == '+')
			sign_count++;
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (dot_count > 1 || sign_count > 0)
		return (0);
	return (1);
}

static double	parse_decimal(char **str)
{
	double	result;
	double	decimal;

	result = 0;
	decimal = 1;
	(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		result += (**str - '0') * pow(10, -decimal);
		decimal++;
		(*str)++;
	}
	return (result);
}

double	ft_atod(char *str)
{
	double	result;
	double	sign;

	result = 0;
	sign = 1;
	if (!is_valid(str))
		error_exit("Invalid number");
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if (*str == '.')
		result += parse_decimal(&str);
	return (result * sign);
}
