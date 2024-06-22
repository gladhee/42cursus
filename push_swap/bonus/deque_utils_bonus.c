/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:35:43 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/12 19:35:43 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
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
