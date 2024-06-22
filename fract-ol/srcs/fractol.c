/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:32:33 by heechoi           #+#    #+#             */
/*   Updated: 2024/05/22 11:35:06 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(int width, int height, t_complex not_used, t_viewport viewport)
{
	t_complex	z;
	t_complex	c;
	int			mandel_n;
	double		tmp_z_re;

	(void)not_used;
	c.re = viewport.center.re + (width - (double)WIDTH / 2) * viewport.scale;
	c.im = viewport.center.im + (height - (double)HEIGHT / 2) * viewport.scale;
	z.re = 0;
	z.im = 0;
	mandel_n = 0;
	while (z.re * z.re + z.im * z.im < 4 && mandel_n < MAX_ITER)
	{
		tmp_z_re = (z.re * z.re) - (z.im * z.im) + c.re;
		z.im = (2 * z.re * z.im) + c.im;
		z.re = tmp_z_re;
		mandel_n++;
	}
	return (mandel_n);
}

int	julia(int width, int height, t_complex c, t_viewport viewport)
{
	t_complex	z;
	int			julia_n;
	double		tmp_z_re;

	(void)viewport;
	z.re = viewport.center.re + (width - (double)WIDTH / 2) * viewport.scale;
	z.im = viewport.center.im + (height - (double)HEIGHT / 2) * viewport.scale;
	julia_n = 0;
	while (z.re * z.re + z.im * z.im < 4 && julia_n < MAX_ITER)
	{
		tmp_z_re = (z.re * z.re) - (z.im * z.im) + c.re;
		z.im = (2 * z.re * z.im) + c.im;
		z.re = tmp_z_re;
		julia_n++;
	}
	return (julia_n);
}

void	set_mandelbrot(void)
{
	t_data	data;

	init_mlx(&data, "Mandelbrot");
	data.fractal = mandelbrot;
	draw_fractal(&data);
	mlx_key_hook(data.mlx_win, my_key_hook, &data);
	mlx_mouse_hook(data.mlx_win, my_mouse_hook, &data);
	mlx_hook(data.mlx_win, 17, 0, my_exit_hook, &data);
	mlx_loop(data.mlx);
}

void	set_julia(t_data data)
{
	init_mlx(&data, "Julia");
	data.fractal = julia;
	draw_fractal(&data);
	mlx_key_hook(data.mlx_win, my_key_hook, &data);
	mlx_mouse_hook(data.mlx_win, my_mouse_hook, &data);
	mlx_hook(data.mlx_win, 17, 0, my_exit_hook, &data);
	mlx_loop(data.mlx);
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc == 1)
		fractol_info();
	else if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		set_mandelbrot();
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (argc != 4)
			fractol_info();
		data.c.re = ft_atod(argv[2]);
		data.c.im = ft_atod(argv[3]);
		set_julia(data);
	}
	else
		fractol_info();
	return (0);
}
