/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:16:47 by heechoi           #+#    #+#             */
/*   Updated: 2023/10/30 10:03:40 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	fnt;
	size_t	bck;
	char	*result;

	fnt = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	bck = ft_strlen(s1);
	while (ft_strchr(set, s1[fnt]) && s1[fnt])
		fnt++;
	while (ft_strrchr(set, s1[bck - 1]) && s1[bck - 1] && bck > fnt)
		bck--;
	result = (char *)malloc(bck - fnt + 1);
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	ft_strlcpy(result, &s1[fnt], bck - fnt + 1);
	return (result);
}
