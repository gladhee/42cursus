/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:22:41 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/12 19:25:48 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_deque	*init_deque(void)
{
	t_deque	*deque;

	deque = (t_deque *)malloc(sizeof(t_deque));
	if (!deque)
		return (NULL);
	deque->size = 0;
	deque->head = NULL;
	deque->rear = NULL;
	return (deque);
}

t_node	*init_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->index = 0;
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
	curr = tmp->head;
	i = 0;
	while (tmp->size > i)
	{
		tmp->head = curr->next;
		free(curr);
		curr = tmp->head;
		i++;
	}
	free(tmp);
	*deque = NULL;
}
