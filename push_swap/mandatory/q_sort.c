/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:23:25 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/13 12:51:46 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_deque *deqye)
{
	int	a;
	int	b;
	int	c;

	a = deqye->head->data;
	b = deqye->head->next->data;
	c = deqye->head->next->next->data;
	if (a < b && b > c && a < c)
	{
		rra_print(deqye);
		sa_print(deqye);
	}
	else if (a > b && b < c && a < c)
		sa_print(deqye);
	else if (a < b && b > c && a > c)
		rra_print(deqye);
	else if (a > b && b < c && a > c)
		ra_print(deqye);
	else if (a > b && b > c && a > c)
	{
		ra_print(deqye);
		sa_print(deqye);
	}
}

int	find_min(t_deque *a)
{
	t_node	*tmp;
	int		min;

	tmp = a->head;
	min = tmp->data;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

int	min_dpt(t_deque *a, int min)
{
	t_node	*tmp;
	int		i;

	tmp = a->head;
	i = 0;
	while (tmp)
	{
		if (tmp->data == min)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void	sort_four(t_deque *a, t_deque *b)
{
	int	dpt;
	int	min;

	min = find_min(a);
	dpt = min_dpt(a, min);
	if (dpt == 1)
		ra_print(a);
	else if (dpt == 2)
	{
		ra_print(a);
		ra_print(a);
	}
	else if (dpt == 3)
		rra_print(a);
	pb_print(a, b);
	sort_three(a);
	pa_print(a, b);
}

void	sort_five(t_deque *a, t_deque *b)
{
	while (a->size >= 4)
	{
		if (a->head->data <= 1)
			rra_print(a);
		while (a->head->data > 1)
			ra_print(a);
		while (a->head->data <= 1)
			pb_print(a, b);
	}
	sort_three(a);
	if (b->head->data == 0)
		sb_print(b);
	while (b->size)
		pa_print(a, b);
}
