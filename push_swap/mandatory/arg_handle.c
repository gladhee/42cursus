/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:21:50 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/12 19:36:53 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	insert_deque(int argc, char **argv, t_deque *a)
{
	int		i;
	int		j;
	int		k;
	char	**arr;

	i = 1;
	k = 0;
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
			a->rear->index = k++;
			free(arr[j]);
			j++;
		}
		free(arr);
		i++;
	}
}
