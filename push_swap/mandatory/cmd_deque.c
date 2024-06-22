/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_deque.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:22:10 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/13 13:21:19 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_head(t_deque *deque, int data)
{
	t_node	*new_node;

	new_node = init_node(data);
	if (!new_node)
		return (error_exit());
	if (deque->size == 0)
	{
		deque->head = new_node;
		deque->rear = new_node;
	}
	else
	{
		new_node->next = deque->head;
		deque->head->prev = new_node;
		deque->head = new_node;
	}
	deque->size++;
}

void	push_rear(t_deque *deque, int data)
{
	t_node	*new_node;

	new_node = init_node(data);
	if (!new_node)
		return (error_exit());
	if (deque->size == 0)
	{
		deque->head = new_node;
		deque->rear = new_node;
	}
	else
	{
		new_node->prev = deque->rear;
		deque->rear->next = new_node;
		deque->rear = new_node;
	}
	deque->size++;
}

int	pop_head(t_deque *deque)
{
	t_node	*tmp;
	int		data;

	if (deque->size == 0)
		return (-1);
	tmp = deque->head;
	data = tmp->data;
	deque->head = deque->head->next;
	free(tmp);
	deque->size--;
	return (data);
}

int	pop_rear(t_deque *deque)
{
	t_node	*tmp;
	int		data;

	if (deque->size == 0)
		return (-1);
	tmp = deque->rear;
	data = tmp->data;
	deque->rear = deque->rear->prev;
	deque->rear->next = NULL;
	free(tmp);
	deque->size--;
	return (data);
}

int	is_empty(t_deque *deque)
{
	if (deque->size == 0)
		return (1);
	return (0);
}
