/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:36:33 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/13 21:57:14 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"
#include "parse.h"
#include "const.h"
#include <stdlib.h>

t_bool	start_bfs(t_info *info, char ***visited, t_deque *deque);
t_bool	is_valid_dir(t_info *info, char **visited, const int *pos);
t_bool	is_valid_pos(t_info *info, const int *pos);
t_deque	*init_deque(void);
void	free_deque(t_deque **deque);
t_bool	push_head(t_deque *deque, int *data);
t_bool	push_rear(t_deque *deque, int *data);
int		*pop_head(t_deque *deque);
t_bool	is_empty(t_deque *deque);
void	put_error_exit(char *msg);
int		*get_new_pos_ptr(void);

t_bool	bfs(t_info *info, char ***visited, int i, int j)
{
	t_deque		*deque;
	int			*pos;

	deque = init_deque();
	if (!deque)
		return (FALSE);
	(*visited)[i][j] = '1';
	pos = get_new_pos_ptr();
	pos[0] = i;
	pos[1] = j;
	push_head(deque, pos);
	while (!is_empty(deque))
	{
		if (!start_bfs(info, visited, deque))
			return (FALSE);
	}
	free_deque(&deque);
	return (TRUE);
}

t_bool	start_bfs(t_info *info, char ***visited, t_deque *deque)
{
	const int	dx[4] = {0, 0, 1, -1};
	const int	dy[4] = {1, -1, 0, 0};
	int			*new_pos;
	int			*pos;
	int			i;

	pos = pop_head(deque);
	i = -1;
	while (++i < 4)
	{
		new_pos = get_new_pos_ptr();
		new_pos[0] = pos[0] + dy[i];
		new_pos[1] = pos[1] + dx[i];
		if (!is_valid_dir(info, *visited, new_pos))
		{
			free(new_pos);
			continue ;
		}
		if (!is_valid_pos(info, new_pos))
			return (FALSE);
		(*visited)[new_pos[0]][new_pos[1]] = '1';
		push_rear(deque, new_pos);
	}
	free(pos);
	return (TRUE);
}

t_bool	is_valid_dir(t_info *info, char **visited, const int *pos)
{
	char	**_map;

	_map = info->map;
	if (pos[0] < 0 || pos[1] < 0)
		return (FALSE);
	if (pos[0] >= info->row || pos[1] >= info->col)
		return (FALSE);
	if (_map[pos[0]][pos[1]] == '1')
		return (FALSE);
	if (visited[pos[0]][pos[1]] == '1')
		return (FALSE);
	return (TRUE);
}

t_bool	is_valid_pos(t_info *info, const int *pos)
{
	char	**_map;

	_map = info->map;
	if (_map[pos[0]][pos[1]] == ' ')
		return (FALSE);
	return (TRUE);
}
