/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:35:04 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/13 13:14:04 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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
