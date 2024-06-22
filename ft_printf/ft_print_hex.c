/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:10:45 by heechoi           #+#    #+#             */
/*   Updated: 2023/11/28 13:47:50 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

char	ft_convert_hex(int c, char format)
{
	if (c <= 9)
		return (c + 48);
	else
	{
		if (format == 'x')
			return (c + 87);
		else
			return (c + 55);
	}
}

size_t	ft_hex_len(unsigned int nbr)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		len++;
		nbr /= 16;
	}
	return (len);
}

char	*ft_uitoxa(unsigned int nbr, char format)
{
	char	*result;
	size_t	len;

	len = ft_hex_len(nbr);
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	result[0] = '0';
	while (nbr)
	{
		result[--len] = ft_convert_hex(nbr % 16, format);
		nbr /= 16;
	}
	return (result);
}

int	ft_print_hex(unsigned int nbr, char format)
{
	char	*result;
	int		len;

	result = ft_uitoxa(nbr, format);
	if (result == NULL)
		return (-1);
	len = ft_print_str(result);
	free(result);
	return (len);
}
