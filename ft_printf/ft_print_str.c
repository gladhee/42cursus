/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:43:07 by heechoi           #+#    #+#             */
/*   Updated: 2023/11/28 13:44:36 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_print_str(char *str)
{
	ssize_t	tmp;

	if (str == NULL)
	{
		tmp = write(1, "(null)", 6);
		if (tmp == -1)
			return (-1);
		return (6);
	}
	tmp = write(1, str, ft_strlen(str));
	if (tmp == -1)
		return (-1);
	return (ft_strlen(str));
}
