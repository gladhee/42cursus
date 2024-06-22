/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:32:53 by heechoi           #+#    #+#             */
/*   Updated: 2024/05/22 11:51:39 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_mlx(t_data *data, char *title)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		error_exit("mlx_init failed");
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, title);
	if (data->mlx_win == NULL)
		error_exit("mlx_new_window failed");
	data->mlx_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->mlx_img == NULL)
		error_exit("mlx_new_image failed");
	data->mlx_addr = mlx_get_data_addr(data->mlx_img, \
		&data->bits_per_pixel, &data->line_length, &data->endian);
	if (data->mlx_addr == NULL)
		error_exit("mlx_get_data_addr failed");
	data->viewport.center = (t_complex){0, 0};
	data->viewport.scale = 4.0 / WIDTH;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx_addr + (y * data->line_length + x * \
		(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	color_set(int iter)
{
	int		opasity;
	int		red;
	int		green;
	int		blue;
	double	t;

	t = (double)iter / (double)MAX_ITER;
	red = 127 * sin(2 * PI * t) + 128;
	green = 127 * sin(2 * PI * t + 2.0 / 3.0 * PI) + 128;
	blue = 127 * sin(2 * PI * t + 4.0 / 3.0 * PI) + 128;
	opasity = 2;
	return (opasity << 24 | red << 16 | green << 8 | blue);
}

void	draw_fractal(t_data *data)
{
	int	x;
	int	y;
	int	iter;

	mlx_clear_window(data->mlx, data->mlx_win);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iter = data->fractal(x, y, data->c, data->viewport);
			if (iter < MAX_ITER)
				my_mlx_pixel_put(data, x, y, color_set(iter + 2));
			else
				my_mlx_pixel_put(data, x, y, color_set(iter << 2));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
}
