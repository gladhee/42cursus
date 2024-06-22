/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:23:17 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/12 19:26:24 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	btoa_base_4(t_deque *a, t_deque *b, int digit, int flag)
{
	int	i;

	i = b->size;
	while (i--)
	{
		if ((base_4(b->head->data) / my_pow(digit)) % 10 == 0)
			btoa_top(a, b, flag);
		else if ((base_4(b->head->data) / my_pow(digit)) % 10 == 1)
			btoa_bottom(a, b, flag);
		else if ((base_4(b->head->data) / my_pow(digit)) % 10 == 2 || \
			base_4(b->head->data) / my_pow(digit) % 10 == 3)
			b_bottom(b, flag);
	}
	while (b->size)
	{
		if (base_4(b->head->data) / my_pow(digit) % 10 == 2)
			btoa_top(a, b, flag);
		else if (base_4(b->head->data) / my_pow(digit) % 10 == 3)
			btoa_bottom(a, b, flag);
	}
}

void	optimize_radix(t_deque *a, t_deque *b, int flag)
{
	atob(a, b, 1, flag);
	btoa(a, b, 2, flag);
	atob(a, b, 3, flag);
	btoa_base_4(a, b, 1, flag);
}

void	radix_sort(t_deque *a, t_deque *b, int flag)
{
	int	digit;
	int	i;

	digit = max_digit(base_3(max_num(a)));
	if (81 < a->size && a->size <= 108)
	{
		optimize_radix(a, b, flag);
		return ;
	}
	i = 1;
	while (i <= digit)
	{
		if (i % 2 == 1)
			atob(a, b, i, flag);
		else if (i % 2 == 0)
			btoa(a, b, i, flag);
		i++;
	}
	if (digit % 2 == 1)
	{
		while (b->size)
			go_a(a, b, flag);
	}
}
