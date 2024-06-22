/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:10:22 by heechoi           #+#    #+#             */
/*   Updated: 2023/11/28 13:39:18 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

unsigned long long	ft_ptr_len(unsigned long long ptr)
{
	unsigned long long	len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (ptr)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

char	*ft_ulltoxa(unsigned long long ptr)
{
	char				*result;
	unsigned long long	len;

	len = ft_ptr_len(ptr);
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	result[0] = '0';
	while (ptr)
	{
		result[--len] = ft_convert_hex(ptr % 16, 'x');
		ptr /= 16;
	}
	return (result);
}

int	ft_print_ptr(void *ptr)
{
	char	*str;
	char	*result;
	int		len;
	int		tmp;

	str = (char *)ptr;
	if (str == NULL)
		return (ft_print_str("0x0"));
	result = ft_ulltoxa((unsigned long long)&str[0]);
	if (result == NULL)
		return (-1);
	tmp = ft_print_str("0x");
	if (tmp == -1)
	{
		free(result);
		return (-1);
	}
	len = ft_print_str(result);
	free(result);
	if (len == -1)
		return (-1);
	return (len + 2);
}
