/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:37:04 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/13 21:37:04 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFS_H
# define BFS_H

typedef char	t_bool;

typedef struct s_node
{
	int				*data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_deque
{
	int		size;
	t_node	*front;
	t_node	*rear;
}				t_deque;

#endif