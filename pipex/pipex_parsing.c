/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:51:15 by heechoi           #+#    #+#             */
/*   Updated: 2024/04/17 22:30:43 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	int		i;

	i = 0;
	if (envp == NULL || *envp == NULL)
		return (PATH);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

void	ft_free2d(char **str, char **str2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	i = 0;
	while (str2[i])
	{
		free(str2[i]);
		str2[i] = NULL;
		i++;
	}
	free(str2);
	str2 = NULL;
}

char	*check_access(char **path_list, char **cmd)
{
	char	*path_cmd;
	char	*tmp;
	int		i;

	i = 0;
	while (path_list[i])
	{
		tmp = ft_strjoin(path_list[i], "/");
		if (!tmp)
			error_exit("malloc");
		path_cmd = ft_strjoin(tmp, cmd[0]);
		ft_free(tmp);
		if (!path_cmd)
			error_exit("malloc");
		if (access(path_cmd, F_OK | X_OK) == 0)
		{
			ft_free2d(cmd, path_list);
			return (path_cmd);
		}
		ft_free(path_cmd);
		i++;
	}
	ft_free2d(cmd, path_list);
	return (NULL);
}

char	*parsing(char *argv, char **envp)
{
	char	**path_list;
	char	**cmd;
	char	*result;

	path_list = ft_split(find_path(envp), ':');
	if (!path_list)
		error_exit("malloc");
	cmd = ft_split(argv, ' ');
	if (!cmd)
		error_exit("malloc");
	result = check_access(path_list, cmd);
	if (!result)
		return (NULL);
	return (result);
}

void	init_info(t_info *info, char **argv, char **envp)
{
	ft_memset(info, 0, sizeof(t_info));
	info->cmd_in = ft_split(argv[2], ' ');
	if (!info->cmd_in)
		error_exit("malloc");
	info->cmd_out = ft_split(argv[3], ' ');
	if (!info->cmd_out)
		error_exit("malloc");
	info->path_cmd_in = parsing(argv[2], envp);
	info->path_cmd_out = parsing(argv[3], envp);
	info->envp = envp;
	info->fd_in = open(argv[1], O_RDONLY);
	if (info->fd_in == -1)
		error_exit(argv[1]);
	info->fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (info->fd_out == -1)
		error_exit(argv[4]);
}
