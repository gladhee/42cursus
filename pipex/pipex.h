/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:32:29 by heechoi           #+#    #+#             */
/*   Updated: 2024/04/17 22:31:18 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include "./Libft/libft.h"

# define READ_END 0
# define WRITE_END 1
# define PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin"

typedef struct s_info
{
	char	**cmd_in;
	char	**cmd_out;
	char	*path_cmd_in;
	char	*path_cmd_out;
	char	**envp;
	pid_t	pid_in;
	pid_t	pid_out;
	int		pipe_fd[2];
	int		fd_in;
	int		fd_out;
	int		status_in;
	int		status_out;
}				t_info;

int		w_int(int w);
int		wstatus(int x);
int		wexitstatus(int status);
int		wifexited(int status);
void	init_info(t_info *info, char **argv, char **envp);
char	*find_path(char **envp);
char	*parsing(char *argv, char **envp);
void	ft_free2d(char **str, char **str2);
int		pipex(t_info *info);
void	in_process(t_info *info);
void	out_process(t_info *info);
void	error_exit(char *str);
void	exec_error(char *cmd);
void	ft_free(char *str);

void	free_all(t_info *info);

#endif