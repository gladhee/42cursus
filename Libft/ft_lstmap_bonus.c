/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:49:34 by heechoi           #+#    #+#             */
/*   Updated: 2023/10/26 16:37:39 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new;
	void	*tmp;

	head = NULL;
	while (lst != NULL && f != NULL && del != NULL)
	{
		tmp = (*f)(lst->content);
		if (tmp == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new = ft_lstnew(tmp);
		if (new == NULL)
		{
			(*del)(tmp);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	new = NULL;
	return (head);
}
