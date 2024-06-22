/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:22:36 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/13 12:15:11 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	base_2(int decimal)
{
	int	quotient;
	int	remainder;
	int	i;
	int	base_2[10];

	i = 0;
	quotient = decimal;
	while (quotient)
	{
		remainder = quotient % 2;
		base_2[i++] = remainder;
		quotient = quotient / 2;
	}
	while (--i >= 0)
	{
		quotient = quotient * 10 + base_2[i];
	}
	return (quotient);
}

int	base_3(int decimal)
{
	int	quotient;
	int	remainder;
	int	i;
	int	base_3[10];

	i = 0;
	quotient = decimal;
	while (quotient)
	{
		remainder = quotient % 3;
		base_3[i++] = remainder;
		quotient = quotient / 3;
	}
	while (--i >= 0)
	{
		quotient = quotient * 10 + base_3[i];
	}
	return (quotient);
}

int	base_4(int decimal)
{
	int	quaternary;
	int	base;
	int	remainder;

	quaternary = 0;
	base = 1;
	while (decimal > 0)
	{
		remainder = decimal % 4;
		quaternary += remainder * base;
		base *= 10;
		decimal /= 4;
	}
	return (quaternary);
}
