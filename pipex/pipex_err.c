/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:07:22 by heechoi           #+#    #+#             */
/*   Updated: 2024/04/17 22:32:02 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_info *info)
{
	ft_free2d(info->cmd_in, info->cmd_out);
	ft_free(info->path_cmd_in);
	ft_free(info->path_cmd_out);
}

void	ft_free(char *str)
{
	free(str);
	str = NULL;
}

void	error_exit(char *str)
{
	extern int	errno;

	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	exec_error(char *cmd)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}
