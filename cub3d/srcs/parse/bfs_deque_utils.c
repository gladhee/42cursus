/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_deque_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:36:30 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/13 21:36:31 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"
#include <stdlib.h>

void	put_error_exit(char *msg);

t_deque	*init_deque(void)
{
	t_deque	*deque;

	deque = (t_deque *)malloc(sizeof(t_deque));
	if (!deque)
		return (NULL);
	deque->front = NULL;
	deque->rear = NULL;
	deque->size = 0;
	return (deque);
}

t_node	*init_node(int *data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	free_deque(t_deque **deque)
{
	t_deque	*tmp;
	t_node	*curr;
	int		i;

	if (!deque || !*deque)
		return ;
	tmp = *deque;
	curr = tmp->front;
	i = 0;
	while (tmp->size > i)
	{
		tmp->front = curr->next;
		free(curr->data);
		free(curr);
		curr = tmp->front;
		i++;
	}
	free(tmp);
	*deque = NULL;
}

int	*get_new_pos_ptr(void)
{
	int	*new_pos;

	new_pos = (int *)malloc(sizeof(int) * 2);
	if (!new_pos)
		put_error_exit("Malloc\n");
	return (new_pos);
}
