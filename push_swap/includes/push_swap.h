/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:30:07 by heechoi           #+#    #+#             */
/*   Updated: 2024/06/13 12:25:28 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../Libft/libft.h"

typedef struct s_index
{
	int	index;
	int	data;
}				t_index;

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_deque
{
	int		size;
	t_node	*head;
	t_node	*rear;
}				t_deque;

/* arg_handle.c */
void	insert_deque(int argc, char **argv, t_deque *a);

/* cmd_atob.c */
void	atob_top(t_deque *a, t_deque *b, int flag);
void	atob_bottom(t_deque *a, t_deque *b, int flag);
void	a_bottom(t_deque *a, int flag);
void	go_b(t_deque *a, t_deque *b, int flag);
void	atob(t_deque *a, t_deque *b, int digit, int flag);

/* cmd_btoa.c */
void	btoa_top(t_deque *a, t_deque *b, int flag);
void	btoa_bottom(t_deque *a, t_deque *b, int flag);
void	b_bottom(t_deque *b, int flag);
void	btoa(t_deque *a, t_deque *b, int digit, int flag);
void	go_a(t_deque *a, t_deque *b, int flag);

/* cmd_deque.c */
void	push_head(t_deque *deque, int data);
void	push_rear(t_deque *deque, int data);
int		pop_head(t_deque *deque);
int		pop_rear(t_deque *deque);
int		is_empty(t_deque *deque);

/* cmd_push.c */
void	pa(t_deque *a, t_deque *b);
void	pb(t_deque *a, t_deque *b);
void	pa_print(t_deque *a, t_deque *b);
void	pb_print(t_deque *a, t_deque *b);

/* cmd_r_rotate.c */
void	rra(t_deque *a);
void	rrb(t_deque *b);
void	rrr(t_deque *a, t_deque *b);
void	rra_print(t_deque *a);
void	rrb_print(t_deque *b);

/* cmd_rotate.c */
void	ra(t_deque *a);
void	rb(t_deque *b);
void	rr(t_deque *a, t_deque *b);
void	ra_print(t_deque *a);
void	rb_print(t_deque *b);

/* cmd_swap.c */
void	sa(t_deque *a);
void	sb(t_deque *b);
void	ss(t_deque *a, t_deque *b);
void	sa_print(t_deque *a);
void	sb_print(t_deque *b);

/* convert_base.c */
int		base_4(int decimal);
int		base_3(int decimal);
int		base_2(int decimal);

/* deque_utils.c */
t_deque	*init_deque(void);
t_node	*init_node(int data);
void	free_deque(t_deque **deque);

/* error_handle.c */
void	error_exit(void);

/* indexing.c */
t_deque	*parsing(int argc, char **argv);

/* normalize.c */
t_deque	*deque_copy(t_deque *deque);
int		find_data(t_deque *deque, int data);
void	set_data(t_deque *deque, int data, int dpt);
void	normalize_input(t_deque *a, t_deque *tmp);

/* push_swap_utils.c */
int		is_sorted(t_deque *a);
int		is_dup(t_deque *a);
void	bubble_sort(t_index *arr, int n);
int		arr_cnt(char **arr);

/* radix.c */
void	radix_sort(t_deque *a, t_deque *b, int flag);

/* radix_utils.c */
int		max_digit(int num);
int		max_num(t_deque *a);
int		my_pow(int digit);

/* sort.c */
void	sort_three(t_deque *a);
void	sort_four(t_deque *a, t_deque *b);
void	sort_five(t_deque *a, t_deque *b);
int		find_min(t_deque *a);

#endif
