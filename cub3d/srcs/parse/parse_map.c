/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:36:38 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/13 21:56:52 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "get_next_line.h"
#include "const.h"
#include "libft.h"

t_bool	set_map(t_info *info, char *line, t_bool *flag);
t_bool	reparse_map(t_info *info);
t_bool	is_valid_map(t_info *info, t_bool flag);
t_bool	realloc_col(char **col, int col_len);
char	**create_double_ptr(void);
char	**words_join(char **words, char *word);
char	**words_dup(char **words);
void	free_words(char **words);
t_bool	bfs(t_info *info, char ***visited, int i, int j);

t_bool	parse_map(t_info *info, int fd)
{
	static t_bool	flag = 0;
	char			*line;
	int				row;

	info->map = create_double_ptr();
	info->map = words_join(info->map, " ");
	row = 0;
	while (TRUE)
	{
		line =get_next_line(fd);
		if (!line)
			break ;
		if (!set_map(info, line, &flag))
			return (FALSE);
		free(line);
		row += 1;
	}
	info->map = words_join(info->map, " ");
	if (!reparse_map(info))
		return (FALSE);
	info->row = row + 2;
	info->col = info->col + 1;
	if (!is_valid_map(info, flag))
		return (FALSE);
	return (TRUE);
}

t_bool	set_map(t_info *info, char *line, t_bool *flag)
{
	int				i;
	int				len;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_strchr(MAP_ELEMENTS, line[i]))
			return (FALSE);
		if (ft_strchr(CARDINAL_DIR, line[i]))
			(*flag)++;
		i++;
	}
	len = (int)ft_strlen(line);
	if (info->col < len)
		info->col = len;
	info->map = words_join(info->map, line);
	if (!info->map)
		return (FALSE);
	return (TRUE);
}

t_bool	reparse_map(t_info *info)
{
	int	i;

	i = 0;
	while (info->map[i])
	{
		if ((int)ft_strlen(info->map[i]) < info->col)
		{
			if (!realloc_col(&(info->map[i]), info->col))
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

t_bool	realloc_col(char **col, int col_len)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(char) * (col_len + 2));
	if (!new)
		return (FALSE);
	new[0] = ' ';
	i = 0;
	while ((*col)[i])
	{
		new[i + 1] = (*col)[i];
		i++;
	}
	while (i < col_len)
	{
		new[i + 1] = ' ';
		i++;
	}
	new[i + 1] = '\0';
	free(*col);
	*col = new;
	return (TRUE);
}

t_bool	is_valid_map(t_info *info, t_bool flag)
{
	char	**visited;
	char	**_map;
	int		i;
	int		j;

	if (flag != 1)
		return (FALSE);
	_map = info->map;
	visited = words_dup(_map);
	i = -1;
	while (_map[++i])
	{
		j = -1;
		while (_map[i][++j])
		{
			if ((_map[i][j] == '0' && visited[i][j] == '0') \
					|| ft_strchr(CARDINAL_DIR, _map[i][j]))
			{
				if (!bfs(info, &visited, i, j))
					return (FALSE);
			}
		}
	}
	free_words(visited);
	return (TRUE);
}
