/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:35:25 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/12 19:35:34 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	sa(t_deque *a)
{
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->head->data;
	a->head->data = a->head->next->data;
	a->head->next->data = tmp;
}

void	sb(t_deque *b)
{
	int	tmp;

	if (b->size < 2)
		return ;
	tmp = b->head->data;
	b->head->data = b->head->next->data;
	b->head->next->data = tmp;
}

void	ss(t_deque *a, t_deque *b)
{
	int	tmp;

	if (a->size < 2 || b->size < 2)
		return ;
	tmp = a->head->data;
	a->head->data = a->head->next->data;
	a->head->next->data = tmp;
	tmp = b->head->data;
	b->head->data = b->head->next->data;
	b->head->next->data = tmp;
}
