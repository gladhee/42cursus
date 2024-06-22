/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:22:16 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/13 11:25:14 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_deque *a, t_deque *b)
{
	if (b->size == 0)
		return ;
	push_head(a, b->head->data);
	pop_head(b);
}

void	pb(t_deque *a, t_deque *b)
{
	if (a->size == 0)
		return ;
	push_head(b, a->head->data);
	pop_head(a);
}

void	pa_print(t_deque *a, t_deque *b)
{
	if (b->size == 0)
		return ;
	push_head(a, b->head->data);
	pop_head(b);
	ft_putstr_fd("pa\n", 1);
}

void	pb_print(t_deque *a, t_deque *b)
{
	if (a->size == 0)
		return ;
	push_head(b, a->head->data);
	pop_head(a);
	ft_putstr_fd("pb\n", 1);
}
