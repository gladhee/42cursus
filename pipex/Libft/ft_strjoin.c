/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:02:18 by heechoi           #+#    #+#             */
/*   Updated: 2023/10/30 21:06:33 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	else if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(s1_len + s2_len + 1);
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	ft_strlcat(result, s1, s1_len + 1);
	ft_strlcat(result, s2, s1_len + s2_len + 1);
	return (result);
}
