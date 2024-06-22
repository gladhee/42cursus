/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:44:04 by heechoi           #+#    #+#             */
/*   Updated: 2023/10/25 15:23:06 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node;

	node = lst;
	if (f == NULL || lst == NULL)
		return ;
	while (node != NULL)
	{
		(*f)(node->content);
		node = node->next;
	}
}
