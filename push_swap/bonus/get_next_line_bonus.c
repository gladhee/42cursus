/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:43:32 by heechoi           #+#    #+#             */
/*   Updated: 2024/04/08 13:53:57 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	remove_gnl(t_gnl **head, int fd)
{
	t_gnl	*pre;
	t_gnl	*node;

	node = *head;
	pre = 0;
	while (node && node->fd != fd)
	{
		pre = node;
		node = node->next;
	}
	if (!node)
		return ;
	if (!pre)
		*head = node->next;
	else
		pre->next = node->next;
	free(node->content);
	node->content = 0;
	free(node);
}

char	*get_content_line(t_gnl *node, long len)
{
	char	*str;
	char	*replace;

	if (!len || node->length < len)
		return (0);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		free(node->content);
		node->content = 0;
		return (0);
	}
	ft_memnullcpy(str, node->content, len);
	replace = ft_content_sub(node, len, node->length - len);
	if (!replace)
	{
		free(str);
		free(node->content);
		node->content = 0;
		return (0);
	}
	free(node->content);
	node->content = replace;
	node->length = node->length - len;
	return (str);
}

char	*get_gnl_line(t_gnl **head, t_gnl *node)
{
	long	i;
	long	res;
	char	*str;

	i = 0;
	while (node->content && i < node->length)
	{
		if (node->content[i] == '\n')
		{
			str = get_content_line(node, i + 1);
			if (!node->content)
				remove_gnl(head, node->fd);
			return (str);
		}
		i++;
	}
	res = read_content(node);
	if (res > 0)
		return (get_gnl_line(head, node));
	str = 0;
	if (res == 0)
		str = get_content_line(node, node->length);
	remove_gnl(head, node->fd);
	return (str);
}

t_gnl	*init_gnl(t_gnl **head, int fd)
{
	t_gnl	*node;

	if (!head || !(*head))
	{
		node = (t_gnl *)malloc(sizeof(t_gnl));
		if (!node)
			return (0);
		node->fd = fd;
		node->content = 0;
		node->length = 0;
		node->next = 0;
		node->size = BUFFER_SIZE;
		if (head)
			*head = node;
		return (node);
	}
	node = *head;
	while (node->next && node->fd != fd)
		node = node->next;
	if (node->fd != fd)
	{
		node->next = init_gnl(0, fd);
		return (node->next);
	}
	return (node);
}

char	*get_next_line(int fd)
{
	static t_gnl	*head;
	t_gnl			*curr;
	char			*line;

	if (fd < 0)
		return (0);
	curr = init_gnl(&head, fd);
	if (!curr)
		return (0);
	line = get_gnl_line(&head, curr);
	return (line);
}
