/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:32:27 by heechoi           #+#    #+#             */
/*   Updated: 2024/04/21 16:09:32 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	out_process(t_info *info)
{
	if (dup2(info->fd_out, STDOUT_FILENO) == -1)
		error_exit("dup2");
	if (dup2(info->pipe_fd[READ_END], STDIN_FILENO) == -1)
		error_exit("dup2");
	if (close(info->fd_out) == -1)
		error_exit("close");
	if (close(info->pipe_fd[READ_END]) == -1)
		error_exit("close");
	if (close(info->pipe_fd[WRITE_END]) == -1)
		error_exit("close");
	if (execve(info->path_cmd_out, info->cmd_out, info->envp) == -1)
		exec_error(info->cmd_out[0]);
}

void	in_process(t_info *info)
{
	if (dup2(info->fd_in, STDIN_FILENO) == -1)
		error_exit("dup2");
	if (dup2(info->pipe_fd[WRITE_END], STDOUT_FILENO) == -1)
		error_exit("dup2");
	if (close(info->fd_in) == -1)
		error_exit("close");
	if (close(info->pipe_fd[READ_END]) == -1)
		error_exit("close");
	if (close(info->pipe_fd[WRITE_END]) == -1)
		error_exit("close");
	if (execve(info->path_cmd_in, info->cmd_in, info->envp) == -1)
		exec_error(info->cmd_in[0]);
}

int	wait_process(t_info *info)
{
	int	exit_status;

	exit_status = EXIT_SUCCESS;
	if (close(info->pipe_fd[READ_END]) == -1)
		error_exit("close");
	if (close(info->pipe_fd[WRITE_END]) == -1)
		error_exit("close");
	waitpid(info->pid_in, &exit_status, 0);
	if (waitpid(info->pid_out, &exit_status, 0))
	{
		if (wifexited(info->status_out))
			exit_status = wexitstatus(info->status_out);
		else
			exit_status = EXIT_FAILURE;
	}
	return (exit_status);
}

int	pipex(t_info *info)
{
	int	exit_status;

	exit_status = EXIT_SUCCESS;
	pipe(info->pipe_fd);
	info->pid_in = fork();
	if (info->pid_in < 0)
		error_exit("fork");
	if (info->pid_in == 0)
		in_process(info);
	else if (info->pid_in > 0)
	{
		info->pid_out = fork();
		if (info->pid_out < 0)
			error_exit("fork");
		if (info->pid_out == 0)
			out_process(info);
		else
			exit_status = wait_process(info);
	}
	return (exit_status);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	int		exit_status;

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", STDERR_FILENO);
		return (1);
	}
	init_info(&info, argv, envp);
	exit_status = pipex(&info);
	free_all(&info);
	return (exit_status);
}
