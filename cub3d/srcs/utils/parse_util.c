/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:36:01 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/13 21:36:02 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_error_exit(char *msg);

char	**create_double_ptr(void)
{
	char	**ptr;

	ptr = (char **)malloc(sizeof(char *) * 1);
	if (!ptr)
		put_error_exit("Malloc\n");
	ptr[0] = NULL;
	return (ptr);
}

char	*nl_trim(const char *line)
{
	char	*new;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 1));
	if (!new)
		put_error_exit("Malloc\n");
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new[i] = line[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**words_join(char **words, char *word)
{
	char	**new;
	int		i;

	i = 0;
	while (words[i])
		i++;
	new = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new)
		put_error_exit("Malloc\n");
	i = 0;
	while (words[i])
	{
		new[i] = words[i];
		i++;
	}
	new[i] = nl_trim(word);
	new[i + 1] = NULL;
	free(words);
	return (new);
}

char	**words_dup(char **words)
{
	char	**new;
	int		i;

	i = 0;
	while (words[i])
		i++;
	new = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new)
		put_error_exit("Malloc\n");
	i = 0;
	while (words[i])
	{
		new[i] = ft_strdup(words[i]);
		if (!new[i])
			put_error_exit("Malloc\n");
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	free_words(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}
