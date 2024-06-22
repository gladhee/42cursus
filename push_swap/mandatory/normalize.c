/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:22:55 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/12 19:25:59 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_deque	*deque_copy(t_deque *deque)
{
	t_deque	*new_a;
	t_node	*node;

	new_a = init_deque();
	if (!new_a)
		return (NULL);
	node = deque->head;
	while (node)
	{
		push_rear(new_a, node->data);
		node = node->next;
	}
	return (new_a);
}

int	find_data(t_deque *deque, int data)
{
	t_node	*node;
	int		i;

	node = deque->head;
	i = 0;
	while (node)
	{
		if (node->data == data)
			return (i);
		node = node->next;
		i++;
	}
	return (-1);
}

void	set_data(t_deque *deque, int data, int dpt)
{
	t_node	*node;
	int		i;

	node = deque->head;
	i = 0;
	while (node)
	{
		if (i == dpt)
		{
			node->data = data;
			break ;
		}
		node = node->next;
		i++;
	}
}

void	normalize_input(t_deque *a, t_deque *tmp)
{
	t_deque	*new_tmp;
	t_node	*node_a;
	int		i;
	int		dpt;

	new_tmp = deque_copy(tmp);
	node_a = a->head;
	i = 0;
	while (node_a)
	{
		dpt = find_data(new_tmp, i);
		set_data(tmp, node_a->data, dpt);
		node_a = node_a->next;
		i++;
	}
	free_deque(&new_tmp);
}
