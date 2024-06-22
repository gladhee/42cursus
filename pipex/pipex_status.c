/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:10:29 by heechoi           #+#    #+#             */
/*   Updated: 2024/04/17 15:43:34 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	w_int(int w)
{
	return (*(int *)&w);
}

int	wstatus(int x)
{
	return (w_int(x) & 0177);
}

int	wexitstatus(int status)
{
	return ((w_int(status) >> 8) & 0x000000ff);
}

int	wifexited(int status)
{
	return (wstatus(status) == 0);
}
