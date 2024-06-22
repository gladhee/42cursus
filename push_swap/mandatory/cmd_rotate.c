/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:22:27 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/13 11:26:29 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_deque *a)
{
	if (a->size < 2)
		return ;
	push_rear(a, a->head->data);
	pop_head(a);
}

void	rb(t_deque *b)
{
	if (b->size < 2)
		return ;
	push_rear(b, b->head->data);
	pop_head(b);
}

void	rr(t_deque *a, t_deque *b)
{
	if (a->size < 2 || b->size < 2)
		return ;
	push_rear(a, a->head->data);
	pop_head(a);
	push_rear(b, b->head->data);
	pop_head(b);
}

void	ra_print(t_deque *a)
{
	if (a->size < 2)
		return ;
	push_rear(a, a->head->data);
	pop_head(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb_print(t_deque *b)
{
	if (b->size < 2)
		return ;
	push_rear(b, b->head->data);
	pop_head(b);
	ft_putstr_fd("rb\n", 1);
}
