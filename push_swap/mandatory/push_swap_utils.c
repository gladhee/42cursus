/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:22:59 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/13 13:17:13 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_dup(t_deque *a)
{
	t_node	*node;
	t_node	*node2;

	node = a->head;
	while (node->next)
	{
		node2 = node->next;
		while (node2)
		{
			if (node->data == node2->data)
				return (1);
			node2 = node2->next;
		}
		node = node->next;
	}
	return (0);
}

int	is_sorted(t_deque *a)
{
	t_node	*node;

	node = a->head;
	while (node->next)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

int	arr_cnt(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	bubble_sort(t_index *arr, int n)
{
	int		i;
	int		j;
	t_index	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j].data > arr[j + 1].data)
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
