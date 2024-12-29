/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:36:09 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/13 21:42:21 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "raycaster.h"
#include "const.h"

void	mlx_hooks(t_mlx *mlx);

t_bool	init_mlx(t_mlx *mlx)
{
	mlx->init = mlx_init();
	if (!mlx->init)
		put_error_exit("mlx_init failed");
	mlx->win = mlx_new_window(mlx->init, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	if (!mlx->win)
		put_error_exit("mlx_new_window failed");
	mlx->img.img = mlx_new_image(mlx->init, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!mlx->img.img)
		put_error_exit("mlx_new_image failed");
	mlx->img.data = \
			(int *)mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	if (!mlx->img.data)
		put_error_exit("mlx_get_data_addr failed");
	mlx_hooks(mlx);
	return (TRUE);
}

void	mlx_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win, KEY_EXIT, 0, &exit_press, mlx);
	mlx_hook(mlx->win, KEY_PRESS, 0, &key_press, mlx);
	mlx_hook(mlx->win, KEY_RELEASE, 0, &key_release, mlx);
}
