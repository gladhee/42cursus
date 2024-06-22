/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:43:38 by heechoi           #+#    #+#             */
/*   Updated: 2023/11/28 13:44:21 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_print_char(char c)
{
	ssize_t	tmp;

	tmp = write(1, &c, 1);
	if (tmp == -1)
		return (-1);
	return (1);
}
