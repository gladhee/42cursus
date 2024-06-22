/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:35:53 by heechoi           #+#    #+#             */
/*   Updated: 2023/10/26 17:00:23 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbr_len(int n)
{
	size_t		len;
	long long	nb;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	if (nb == 0)
		return (1);
	while (nb)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*result;
	size_t		len;
	long long	nb;

	len = ft_nbr_len(n);
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	nb = n;
	result[len] = '\0';
	result[0] = '0';
	if (nb < 0)
	{
		result[0] = '-';
		nb *= -1;
	}
	while (nb)
	{
		result[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (result);
}
