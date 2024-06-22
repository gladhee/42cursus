/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:37:22 by heechoi           #+#    #+#             */
/*   Updated: 2023/10/19 15:48:19 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	s1_tmp;
	unsigned char	s2_tmp;
	size_t			i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			s1_tmp = (unsigned char)s1[i];
			s2_tmp = (unsigned char)s2[i];
			return (s1_tmp - s2_tmp);
		}
		i++;
	}
	return (0);
}
