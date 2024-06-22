/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_atob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:21:58 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/13 12:26:31 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	atob_top(t_deque *a, t_deque *b, int flag)
{
	pb(a, b);
	if (flag)
		ft_putstr_fd("pb\n", 1);
}

void	atob_bottom(t_deque *a, t_deque *b, int flag)
{
	pb(a, b);
	rb(b);
	if (flag)
		ft_putstr_fd("pb\nrb\n", 1);
}

void	a_bottom(t_deque *a, int flag)
{
	ra(a);
	if (flag)
		ft_putstr_fd("ra\n", 1);
}

void	go_b(t_deque *a, t_deque *b, int flag)
{
	pb(a, b);
	if (flag)
		ft_putstr_fd("pb\n", 1);
}

void	atob(t_deque *a, t_deque *b, int digit, int flag)
{
	int	i;

	i = a->size;
	while (i)
	{
		if (((base_3(a->head->data)) / my_pow(digit)) % 10 == 0)
			atob_top(a, b, flag);
		else if (((base_3(a->head->data)) / my_pow(digit)) % 10 == 1)
			atob_bottom(a, b, flag);
		else if (((base_3(a->head->data)) / my_pow(digit)) % 10 == 2)
			a_bottom(a, flag);
		i--;
	}
	while (a->size)
		go_b(a, b, flag);
}
