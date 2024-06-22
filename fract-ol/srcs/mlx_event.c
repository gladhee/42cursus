/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:32:46 by heechoi           #+#    #+#             */
/*   Updated: 2024/05/22 12:06:36 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	my_key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(data->mlx, data->mlx_img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	return (0);
}

int	my_exit_hook(t_data *data)
{
	mlx_destroy_image(data->mlx, data->mlx_img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

int	my_mouse_hook(int mousecode, int x, int y, t_data *data)
{
	double	zoom_factor;

	x = 0;
	y = 0;
	if (mousecode == SCROLL_UP)
		zoom_factor = 0.9;
	else if (mousecode == SCROLL_DOWN)
		zoom_factor = 1.1;
	else
		return (0);
	data->viewport.scale *= zoom_factor;
	draw_fractal(data);
	return (0);
}
