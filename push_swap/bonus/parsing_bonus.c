/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:35:49 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/12 19:35:50 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	insert_deque(int argc, char **argv, t_deque *a)
{
	int		i;
	int		j;
	char	**arr;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			error_exit();
		arr = ft_split(argv[i], ' ');
		if (!arr)
			error_exit();
		j = 0;
		while (arr[j])
		{
			push_rear(a, ft_atoi(arr[j]));
			free(arr[j]);
			j++;
		}
		free(arr);
		i++;
	}
}

int	is_dup(t_deque *a)
{
	t_node	*cur;
	t_node	*cmp;

	cur = a->head;
	while (cur)
	{
		cmp = cur->next;
		while (cmp)
		{
			if (cur->data == cmp->data)
				return (1);
			cmp = cmp->next;
		}
		cur = cur->next;
	}
	return (0);
}

t_deque	*parsing(int argc, char **argv)
{
	t_deque	*a;

	a = init_deque();
	if (!a)
		error_exit();
	if (argv[1][0] == '\0')
		error_exit();
	insert_deque(argc, argv, a);
	if (is_dup(a))
		error_exit();
	if (a->size == 0)
		error_exit();
	return (a);
}
