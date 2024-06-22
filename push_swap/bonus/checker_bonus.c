/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:33:52 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/13 13:31:56 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_sorted(t_deque *deque)
{
	t_node	*node;

	node = deque->head;
	while (node && node->next)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

int	execute_cmd(t_deque *a, t_deque *b, char *cmd)
{
	if (!ft_strncmp(cmd, "sa\n", 3))
		sa(a);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		sb(b);
	else if (!ft_strncmp(cmd, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(cmd, "pa\n", 3))
		pa(a, b);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		pb(a, b);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		ra(a);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		rb(b);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		rra(a);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		rrb(b);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		rrr(a, b);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_deque	*a;
	t_deque	*b;
	char	*cmd;

	if (argc == 1)
		return (0);
	a = parsing(argc, argv);
	b = init_deque();
	while (1)
	{
		cmd = get_next_line(0);
		if (cmd <= 0)
			break ;
		if (!execute_cmd(a, b, cmd))
			error_exit();
		free(cmd);
	}
	cmd = NULL;
	if (is_sorted(a) && is_empty(b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_deque(&a);
	free_deque(&b);
	return (0);
}
