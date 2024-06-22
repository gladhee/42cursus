/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:30:09 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/12 19:33:35 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "../Libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_deque
{
	int		size;
	t_node	*head;
	t_node	*rear;
}				t_deque;

/* get_next_line.c */
typedef struct s_gnl
{
	int				fd;
	char			*content;
	long			length;
	long			size;
	struct s_gnl	*next;
}					t_gnl;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

void	remove_list(t_gnl **head, int fd);
char	*get_content_line(t_gnl *node, long len);
char	*get_gnl_line(t_gnl **head, t_gnl *node);
t_gnl	*init_gnl(t_gnl **head, int fd);
char	*get_next_line(int fd);
void	ft_memnullcpy(void *dst, const void *src, size_t n);
char	*ft_content_sub(t_gnl *node, unsigned int start, long len);
long	read_content(t_gnl *node);

/* checker_bonus.c */
void	error_exit(void);

/* deque_utils_bonus.c */
t_deque	*init_deque(void);
t_node	*init_node(int data);
void	free_deque(t_deque **deque);

/* cmd_deque_bonus.c */
int		is_empty(t_deque *deque);
void	push_head(t_deque *deque, int data);
void	push_rear(t_deque *deque, int data);
int		pop_head(t_deque *deque);
int		pop_rear(t_deque *deque);

/* cmd_push_bonus.c */
void	pa(t_deque *a, t_deque *b);
void	pb(t_deque *a, t_deque *b);

/* cmd_swap_bonus.c */
void	sa(t_deque *a);
void	sb(t_deque *b);
void	ss(t_deque *a, t_deque *b);

/* cmd_rotate_bonus.c */
void	ra(t_deque *a);
void	rb(t_deque *b);
void	rr(t_deque *a, t_deque *b);

/* cmd_r_rotate_bonus.c */
void	rra(t_deque *a);
void	rrb(t_deque *b);
void	rrr(t_deque *a, t_deque *b);

/* parsing_bonus.c */
t_deque	*parsing(int argc, char **argv);

#endif
