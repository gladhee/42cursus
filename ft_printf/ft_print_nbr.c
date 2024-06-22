/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:42:45 by heechoi           #+#    #+#             */
/*   Updated: 2023/11/28 13:44:31 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_print_nbr(int nbr)
{
	char	*result;
	int		len;

	result = ft_itoa(nbr);
	if (result == NULL)
		return (-1);
	len = ft_print_str(result);
	free(result);
	return (len);
}
