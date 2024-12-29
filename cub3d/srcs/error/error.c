/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:36:49 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/13 21:36:50 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

void	free_words(char **words);

t_bool	argc_error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Invalid number of arguments\n", 2);
	ft_putstr_fd("Usage: ./cub3D <map_name.cub>\n", 2);
	exit(EXIT_FAILURE);
}

t_bool	put_error_exit(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}
