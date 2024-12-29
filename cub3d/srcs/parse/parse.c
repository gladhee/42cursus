/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:36:40 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/13 21:57:30 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include "const.h"
#include <fcntl.h>

t_bool	is_valid_filename(char *filename, char **path);
t_bool	put_error_exit(char *msg);
t_bool	parse_ident(t_ident *ident, int fd);
t_bool	parse_map(t_info *info, int fd);

t_bool	parse(t_info *info, char *filename)
{
	char	*path;
	int		fd;

	if (!is_valid_filename(filename, &path))
		put_error_exit("Invalid file extension\n");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		put_error_exit("Failed to open file\n");
	free(path);
	if (!parse_ident(&(info->ident), fd))
		put_error_exit("Failed to parse identifier\n");
	if (!parse_map(info, fd))
		put_error_exit("Failed to parse info\n");
	close(fd);
	return (TRUE);
}

t_bool	is_valid_filename(char *filename, char **path)
{
	if (ft_strncmp(filename + ft_strlen(filename) - 4, EXT, 4))
		return (FALSE);
	if (ft_strchr(filename, '/'))
	{
		*path = ft_strdup(filename);
		if (!*path)
			return (FALSE);
		return (TRUE);
	}
	*path = ft_strjoin(MAP_DIR, filename);
	if (!*path)
		return (FALSE);
	return (TRUE);
}
