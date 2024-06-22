/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:48:22 by heechoi           #+#    #+#             */
/*   Updated: 2023/10/25 15:38:39 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	if (dst == src)
		return (dst);
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	while (n--)
		*dst_tmp++ = *src_tmp++;
	return (dst);
}
