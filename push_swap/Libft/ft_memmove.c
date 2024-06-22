/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:51:04 by heechoi           #+#    #+#             */
/*   Updated: 2023/10/25 16:58:42 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	if (dst == src)
		return (dst);
	if (dst < src)
	{
		dst_tmp = (unsigned char *)dst;
		src_tmp = (unsigned char *)src;
		while (len--)
			*dst_tmp++ = *src_tmp++;
	}
	else
	{
		dst_tmp = (unsigned char *)dst + (len - 1);
		src_tmp = (unsigned char *)src + (len - 1);
		while (len--)
			*dst_tmp-- = *src_tmp--;
	}
	return (dst);
}
