/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:22:22 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/13 11:25:59 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_deque *a)
{
	if (a->size < 2)
		return ;
	push_head(a, a->rear->data);
	pop_rear(a);
}

void	rrb(t_deque *b)
{
	if (b->size < 2)
		return ;
	push_head(b, b->rear->data);
	pop_rear(b);
}

void	rrr(t_deque *a, t_deque *b)
{
	if (a->size < 2 || b->size < 2)
		return ;
	push_head(a, a->rear->data);
	pop_rear(a);
	push_head(b, b->rear->data);
	pop_rear(b);
}

void	rra_print(t_deque *a)
{
	if (a->size < 2)
		return ;
	push_head(a, a->rear->data);
	pop_rear(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb_print(t_deque *b)
{
	if (b->size < 2)
		return ;
	push_head(b, b->rear->data);
	pop_rear(b);
	ft_putstr_fd("rrb\n", 1);
}
