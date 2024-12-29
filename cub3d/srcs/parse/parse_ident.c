/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ident.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:36:35 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/13 21:57:00 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "const.h"
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>

t_bool	set_ident(t_ident *ident, char *line);
t_bool	check_ident(t_ident *ident);
t_bool	check_texture(char *path);
t_bool	check_color(char *color);
char	*nl_trim(const char *line);
void	is_digit_color(char *color);
void	is_valid_color(const char *color_set);

t_bool	parse_ident(t_ident *ident, int fd)
{
	char	*line;
	int		flag;

	flag = 0;
	while (TRUE)
	{
		if (flag == 6)
			break ;
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		if (!set_ident(ident, line))
			return (FALSE);
		flag++;
		free(line);
	}
	if (!check_ident(ident))
		return (FALSE);
	return (TRUE);
}

t_bool	set_ident(t_ident *ident, char *line)
{
	char	**split;

	split = ft_split(line, DELIMITER_SPACE);
	if (!split)
		return (FALSE);
	if (split[2] != NULL)
		return (FALSE);
	if (ft_strncmp(split[IDENT], "NO", 3) == 0)
		ident->no_path = nl_trim(split[IDENT_INFO]);
	else if (ft_strncmp(split[IDENT], "SO", 3) == 0)
		ident->so_path = nl_trim(split[IDENT_INFO]);
	else if (ft_strncmp(split[IDENT], "WE", 3) == 0)
		ident->we_path = nl_trim(split[IDENT_INFO]);
	else if (ft_strncmp(split[IDENT], "EA", 3) == 0)
		ident->ea_path = nl_trim(split[IDENT_INFO]);
	else if (ft_strncmp(split[IDENT], "F", 2) == 0)
		ident->f_color = nl_trim(split[IDENT_INFO]);
	else if (ft_strncmp(split[IDENT], "C", 2) == 0)
		ident->c_color = nl_trim(split[IDENT_INFO]);
	else
		return (FALSE);
	free(split[IDENT]);
	free(split[IDENT_INFO]);
	free(split);
	return (TRUE);
}

t_bool	check_ident(t_ident *ident)
{
	if (!check_texture(ident->no_path))
		return (FALSE);
	if (!check_texture(ident->so_path))
		return (FALSE);
	if (!check_texture(ident->we_path))
		return (FALSE);
	if (!check_texture(ident->ea_path))
		return (FALSE);
	if (!check_color(ident->f_color))
		return (FALSE);
	if (!check_color(ident->c_color))
		return (FALSE);
	return (TRUE);
}

t_bool	check_texture(char *path)
{
	int	fd;

	if (!path)
		return (FALSE);
	if (ft_strncmp(path + ft_strlen(path) - EXT_XPM_SIZE, EXT_XPM,
			EXT_XPM_SIZE))
		return (FALSE);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	close(fd);
	return (TRUE);
}

t_bool	check_color(char *color)
{
	char	**split;
	int		_color;
	int		i;

	if (!color)
		return (FALSE);
	is_valid_color(color);
	split = ft_split(color, DELIMITER_COMMA);
	if (!split)
		return (FALSE);
	i = 0;
	while (split[i])
	{
		is_digit_color(split[i]);
		_color = ft_atoi(split[i]);
		if (_color < COLOR_MIN || _color > COLOR_MAX)
			return (FALSE);
		free(split[i]);
		i++;
	}
	if (i != COLOR_SIZE)
		return (FALSE);
	free(split);
	return (TRUE);
}
