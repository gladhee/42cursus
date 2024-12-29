/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_deque_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:36:28 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/13 21:36:28 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"
#include "const.h"
#include <stdlib.h>

t_node	*init_node(int *pos);
t_bool	put_error_exit(char *msg);

t_bool	push_head(t_deque *deque, int *data)
{
	t_node	*new_node;

	new_node = init_node(data);
	if (!new_node)
		put_error_exit("Malloc\n");
	if (deque->size == 0)
	{
		deque->front = new_node;
		deque->rear = new_node;
	}
	else
	{
		new_node->next = deque->front;
		deque->front->prev = new_node;
		deque->front = new_node;
	}
	deque->size++;
	return (TRUE);
}

t_bool	push_rear(t_deque *deque, int *data)
{
	t_node	*new_node;

	new_node = init_node(data);
	if (!new_node)
		put_error_exit("Malloc\n");
	if (deque->size == 0)
	{
		deque->front = new_node;
		deque->rear = new_node;
	}
	else
	{
		new_node->prev = deque->rear;
		deque->rear->next = new_node;
		deque->rear = new_node;
	}
	deque->size++;
	return (TRUE);
}

int	*pop_head(t_deque *deque)
{
	t_node	*tmp;
	int		*data;

	if (deque->size == 0)
		return (NULL);
	tmp = deque->front;
	data = tmp->data;
	deque->front = deque->front->next;
	free(tmp);
	tmp = NULL;
	deque->size--;
	return (data);
}

t_bool	is_empty(t_deque *deque)
{
	if (deque->size == 0)
		return (TRUE);
	return (FALSE);
}
