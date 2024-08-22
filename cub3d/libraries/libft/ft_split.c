/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:17:27 by heechoi           #+#    #+#             */
/*   Updated: 2023/10/26 17:03:55 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_cnt(const char *s, char c)
{
	size_t	word_cnt;
	size_t	i;

	word_cnt = 0;
	i = 0;
	if (s[0] != c && s[0] != '\0')
		word_cnt++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			word_cnt++;
		i++;
	}
	return (word_cnt);
}

static char	*ft_word_split(const char *s, char c)
{
	char	*result;
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	result = (char *)malloc(i + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	**ft_free(char **result)
{
	size_t	i;

	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		result[i] = NULL;
		i++;
	}
	free(result);
	result = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;

	if (s == NULL)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_word_cnt(s, c) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			result[i] = ft_word_split(s, c);
			if (result[i] == NULL)
				return (ft_free(result));
			i++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	result[i] = NULL;
	return (result);
}
