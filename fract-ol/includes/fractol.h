/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:05:38 by heechoi           #+#    #+#             */
/*   Updated: 2024/07/09 13:06:22 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../Libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# define WIDTH 1280
# define HEIGHT 720
# define MAX_ITER 150
# define ESC 53
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define PI 3.14159265

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_viewport
{
	t_complex	center;
	double		scale;
}				t_viewport;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*mlx_img;
	char		*mlx_addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			(*fractal)(int, int, t_complex *, t_viewport *);
	t_viewport	viewport;
	t_complex	c;
}				t_data;

void	init_mlx(t_data *data, char *title);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		color_set(int iter);
void	draw_fractal(t_data *data);
void	set_mandelbrot(void);
int		mandelbrot(int width, int height, t_complex not_used, \
			t_viewport viewport);
void	set_julia(t_data data);
int		julia(int width, int height, t_complex c, t_viewport viewport);
double	ft_atod(char *str);
void	error_exit(char *str);
void	fractol_info(void);
int		my_key_hook(int keycode, t_data *data);
int		my_mouse_hook(int mousecode, int x, int y, t_data *data);
int		my_exit_hook(t_data *data);

#endif