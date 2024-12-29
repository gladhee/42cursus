/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:36:20 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/13 22:02:39 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"
#include "const.h"
#include "math.h"

void	move_player(t_mlx *mlx);
void	draw_wall(t_mlx *mlx, t_calc *calc, int x);
void	calculate_wall(t_mlx *mlx, t_calc *calc);

void	set_ray(t_mlx *mlx, t_calc *calc, int x)
{
	calc->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	calc->ray_dir_x = mlx->ray.dir_x + mlx->ray.plane_x * calc->camera_x;
	calc->ray_dir_y = mlx->ray.dir_y + mlx->ray.plane_y * calc->camera_x;
	calc->map_x = (int)mlx->ray.pos_x;
	calc->map_y = (int)mlx->ray.pos_y;
	calc->delta_dist_x = fabs(1 / calc->ray_dir_x);
	calc->delta_dist_y = fabs(1 / calc->ray_dir_y);
	calc->hit = 0;
}

void	init_dda(t_mlx *mlx, t_calc *calc)
{
	if (calc->ray_dir_x < 0)
	{
		calc->step_x = -1;
		calc->side_dist_x = (mlx->ray.pos_x - calc->map_x) * calc->delta_dist_x;
	}
	else
	{
		calc->step_x = 1;
		calc->side_dist_x = \
				(calc->map_x + 1.0 - mlx->ray.pos_x) * calc->delta_dist_x;
	}
	if (calc->ray_dir_y < 0)
	{
		calc->step_y = -1;
		calc->side_dist_y = \
				(mlx->ray.pos_y - calc->map_y) * calc->delta_dist_y;
	}
	else
	{
		calc->step_y = 1;
		calc->side_dist_y = \
				(calc->map_y + 1.0 - mlx->ray.pos_y) * calc->delta_dist_y;
	}
}

void	perform_dda(t_mlx *mlx, t_calc *calc)
{
	while (calc->hit == 0)
	{
		if (calc->side_dist_x < calc->side_dist_y)
		{
			calc->side_dist_x += calc->delta_dist_x;
			calc->map_x += calc->step_x;
			calc->side = 0;
		}
		else
		{
			calc->side_dist_y += calc->delta_dist_y;
			calc->map_y += calc->step_y;
			calc->side = 1;
		}
		if (mlx->info.map[calc->map_x][calc->map_y] == '1')
			calc->hit = 1;
	}
	if (calc->side == 0)
		calc->perp_wall_dist = (calc->map_x - mlx->ray.pos_x + \
							(1 - (float)calc->step_x) / 2) / calc->ray_dir_x;
	else
		calc->perp_wall_dist = (calc->map_y - mlx->ray.pos_y + \
							(1 - (float)calc->step_y) / 2) / calc->ray_dir_y;
}
