/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:23:08 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/12 19:23:09 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	max_num(t_deque *a)
{
	t_node	*node;
	int		max;

	node = a->head;
	max = 0;
	while (node)
	{
		if (node->data > max)
			max = node->data;
		node = node->next;
	}
	return (max);
}

int	max_digit(int num)
{
	int	digit;

	digit = 0;
	while (num)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

int	my_pow(int digit)
{
	int	res;

	res = 1;
	while (--digit)
		res *= 10;
	return (res);
}
