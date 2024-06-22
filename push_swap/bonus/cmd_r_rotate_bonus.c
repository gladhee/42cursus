/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r_rotate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:35:13 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/13 13:13:33 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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
	rra(a);
	rrb(b);
}
