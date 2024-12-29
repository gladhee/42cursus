/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:36:06 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/13 21:43:40 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"
#include "mlx.h"
#include "const.h"
#include "libft.h"

void	get_texture(t_mlx *mlx, char *path, int *texture)
{
	t_img	img;
	int		x;
	int		y;

	img.img = mlx_xpm_file_to_image(mlx->init, path, &img.width, &img.height);
	img.data = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	y = -1;
	while (++y < img.height)
	{
		x = -1;
		while (++x < img.width)
			texture[img.width * y + x] = img.data[img.width * y + x];
	}
	mlx_destroy_image(mlx->init, img.img);
}

void	load_image(t_mlx *mlx)
{
	int	i;

	i = -1;
	mlx->texture = (int **)ft_calloc(sizeof (int *) * 4, 1);
	if (!mlx->texture)
		put_error_exit("mlx->texture malloc failed");
	while (++i < 4)
	{
		mlx->texture[i] = (int *)ft_calloc(sizeof(int) * \
				TEXTURE_WIDTH * TEXTURE_HEIGHT, 1);
		if (!mlx->texture[i])
			put_error_exit("mlx->texture[i] malloc failed");
	}
	get_texture(mlx, mlx->info.ident.no_path, mlx->texture[NO]);
	get_texture(mlx, mlx->info.ident.so_path, mlx->texture[SO]);
	get_texture(mlx, mlx->info.ident.we_path, mlx->texture[WE]);
	get_texture(mlx, mlx->info.ident.ea_path, mlx->texture[EA]);
}
