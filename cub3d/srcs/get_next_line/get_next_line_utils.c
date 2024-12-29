/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:23:34 by heechoi           #+#    #+#             */
/*   Updated: 2024/04/08 13:43:14 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	f_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_;
	const char	*src_;

	if (dst == 0 || src == 0 || n <= 0)
		return ;
	dst_ = (char *)dst;
	src_ = (const char *)src;
	while (n-- > 0)
		*dst_++ = *src_++;
	*dst_ = '\0';
}

char	*ft_content_sub(t_gnl *node, unsigned int start, long len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * node->size);
	if (!str)
		return (0);
	f_memcpy(str, (node->content) + start, len);
	return (str);
}

static char	*ft_content_concat(t_gnl *node, char *buf, long res)
{
	char	*tmp;
	long	size;

	if (node->content && node->size > node->length + res)
	{
		f_memcpy((node->content) + node->length, buf, res);
		node->length += res;
		return (node->content);
	}
	size = node->size * 2;
	if (size < node->length + res)
		size = node->length + res;
	tmp = (char *)malloc(sizeof(char) * (size));
	if (!tmp)
		return (0);
	f_memcpy(tmp, node->content, node->length);
	f_memcpy(tmp + node->length, buf, res);
	free(node->content);
	node->content = tmp;
	node->length += res;
	node->size = size;
	return (node->content);
}

long	read_content(t_gnl *node)
{
	char	buf[BUFFER_SIZE];
	long	res;
	char	*content;

	res = read(node->fd, buf, BUFFER_SIZE);
	if (res > 0)
	{
		content = ft_content_concat(node, buf, res);
		if (!content)
			return (-1);
	}
	return (res);
}
