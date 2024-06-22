/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:23:05 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/13 12:59:50 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push_swap(t_deque *a, t_deque *b, t_deque *tmp)
{
	if (is_sorted(a))
		;
	else if (a->size == 2)
	{
		sa(a);
		ft_putstr_fd("sa\n", 1);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
	{
		radix_sort(a, b, 0);
		normalize_input(a, tmp);
		radix_sort(tmp, b, 1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_deque	*a;
	t_deque	*b;
	t_deque	*tmp;

	if (argc < 2)
		return (0);
	a = parsing(argc, argv);
	tmp = parsing(argc, argv);
	b = init_deque();
	if (!b)
		error_exit();
	push_swap(a, b, tmp);
	free_deque(&a);
	free_deque(&b);
	free_deque(&tmp);
	return (0);
}
