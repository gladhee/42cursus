/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:23:57 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/15 20:23:57 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"
#include "const.h"

void	free_words(char **words);

void	free_info(t_info *info)
{
	free_words(info->map);
	free(info->ident.no_path);
	free(info->ident.so_path);
	free(info->ident.we_path);
	free(info->ident.ea_path);
	free(info->ident.c_color);
	free(info->ident.f_color);
}

void	free_tex_buf(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(mlx->texture[i]);
		i++;
	}
	free(mlx->texture);
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		free(mlx->buf[i]);
		i++;
	}
	free(mlx->buf);
}
