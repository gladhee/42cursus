/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_nbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:09:30 by heechoi           #+#    #+#             */
/*   Updated: 2023/11/28 00:42:16 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

size_t	ft_nbr_len(unsigned int nbr)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int nbr)
{
	char	*result;
	size_t	len;

	len = ft_nbr_len(nbr);
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	result[0] = '0';
	while (nbr)
	{
		result[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (result);
}

int	ft_print_unsigned_nbr(unsigned int nbr)
{
	char	*result;
	int		len;

	result = ft_uitoa(nbr);
	if (result == NULL)
		return (-1);
	len = ft_print_str(result);
	free(result);
	return (len);
}
