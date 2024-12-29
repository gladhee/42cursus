/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:40:43 by heechoi           #+#    #+#             */
/*   Updated: 2024/04/08 13:36:30 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

typedef struct s_gnl
{
	int				fd;
	char			*content;
	long			length;
	long			size;
	struct s_gnl	*next;
}					t_gnl;

void	remove_list(t_gnl **head, int fd);
char	*get_content_line(t_gnl *node, long len);
char	*get_gnl_line(t_gnl **head, t_gnl *node);
t_gnl	*init_gnl(t_gnl **head, int fd);
char	*get_next_line(int fd);

void	f_memcpy(void *dst, const void *src, size_t n);
char	*ft_content_sub(t_gnl *node, unsigned int start, long len);
long	read_content(t_gnl *node);

#endif