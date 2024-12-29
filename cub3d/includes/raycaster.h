/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:37:12 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/13 21:37:12 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include "parse.h"
# include <math.h>
# include <stdlib.h>

typedef struct s_ray
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}		t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}		t_img;

typedef struct s_calc
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_num;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
}		t_calc;

typedef struct s_mlx
{
	void		*init;
	void		*win;
	t_img		img;
	t_bool		key_w;
	t_bool		key_a;
	t_bool		key_s;
	t_bool		key_d;
	t_bool		key_left;
	t_bool		key_right;
	int			**buf;
	int			**texture;
	int			c_color;
	int			f_color;
	t_info		info;
	t_ray		ray;
}		t_mlx;

int		exit_press(t_mlx *mlx);
int		key_press(int keycode, t_mlx *mlx);
int		key_release(int keycode, t_mlx *mlx);

t_bool	put_error_exit(char *msg);

#endif