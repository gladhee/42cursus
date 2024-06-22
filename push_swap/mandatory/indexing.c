/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:22:52 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/12 19:39:48 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*indexing(t_index *arr, int size)
{
	int	*indexed;
	int	i;

	indexed = (int *)malloc(sizeof(int) * size);
	if (!indexed)
		error_exit();
	i = 0;
	while (i < size)
	{
		indexed[arr[i].index] = i;
		i++;
	}
	return (indexed);
}

int	*collect_index(t_deque *deque)
{
	t_node	*cur;
	int		*indexed;
	t_index	*arr;
	int		i;

	arr = (t_index *)malloc(sizeof(t_index) * deque->size);
	if (!arr)
		error_exit();
	cur = deque->head;
	i = 0;
	while (cur)
	{
		arr[i].data = cur->data;
		arr[i].index = i;
		cur = cur->next;
		i++;
	}
	bubble_sort(arr, deque->size);
	indexed = indexing(arr, deque->size);
	free(arr);
	arr = NULL;
	return (indexed);
}

t_deque	*indexed_init(int *arr, int size)
{
	t_deque	*deque;
	int		i;

	deque = init_deque();
	if (!deque)
		error_exit();
	i = 0;
	while (i < size)
	{
		push_rear(deque, arr[i]);
		i++;
	}
	return (deque);
}

t_deque	*parsing(int argc, char **argv)
{
	t_deque	*a;
	int		*indexed;
	int		size;

	a = init_deque();
	if (!a)
		error_exit();
	insert_deque(argc, argv, a);
	if (is_dup(a))
		error_exit();
	indexed = collect_index(a);
	size = a->size;
	free_deque(&a);
	a = indexed_init(indexed, size);
	free(indexed);
	indexed = NULL;
	return (a);
}
