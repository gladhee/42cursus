/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:24:00 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/15 20:24:01 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"

t_bool	put_error_exit(char *msg);

void	is_digit_color(char *color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (!ft_isdigit(color[i]))
			put_error_exit("Invalid color\n");
		i++;
	}
}

void	is_valid_color(const char *color_set)
{
	int	i;
	int	comma_count;

	i = 0;
	comma_count = 0;
	while (color_set[i])
	{
		if (color_set[i] == ',')
			comma_count++;
		i++;
	}
	if (comma_count != 2)
		put_error_exit("Invalid color\n");
}
