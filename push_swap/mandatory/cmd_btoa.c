/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_btoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:22:03 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/12 19:22:04 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	btoa_top(t_deque *a, t_deque *b, int flag)
{
	pa(a, b);
	if (flag)
		ft_putstr_fd("pa\n", 1);
}

void	btoa_bottom(t_deque *a, t_deque *b, int flag)
{
	pa(a, b);
	ra(a);
	if (flag)
		ft_putstr_fd("pa\nra\n", 1);
}

void	b_bottom(t_deque *b, int flag)
{
	rb(b);
	if (flag)
		ft_putstr_fd("rb\n", 1);
}

void	go_a(t_deque *a, t_deque *b, int flag)
{
	pa(a, b);
	if (flag)
		ft_putstr_fd("pa\n", 1);
}

void	btoa(t_deque *a, t_deque *b, int digit, int flag)
{
	int	i;

	i = b->size;
	while (i--)
	{
		if (((base_3(b->head->data)) / my_pow(digit)) % 10 == 0)
			btoa_top(a, b, flag);
		else if (((base_3(b->head->data)) / my_pow(digit)) % 10 == 1)
			btoa_bottom(a, b, flag);
		else if (((base_3(b->head->data)) / my_pow(digit)) % 10 == 2)
			b_bottom(b, flag);
	}
	while (b->size)
		go_a(a, b, flag);
}
