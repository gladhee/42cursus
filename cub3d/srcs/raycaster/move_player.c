/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:31:43 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/16 18:31:44 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"
#include "const.h"

void	move_forward(t_mlx *mlx);
void	move_backward(t_mlx *mlx);
void	move_left(t_mlx *mlx);
void	move_right(t_mlx *mlx);

void	rotate_vec(t_mlx *mlx, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = mlx->ray.dir_x;
	mlx->ray.dir_x = mlx->ray.dir_x * cos(angle) - mlx->ray.dir_y * sin(angle);
	mlx->ray.dir_y = old_dir_x * sin(angle) + mlx->ray.dir_y * cos(angle);
	old_plane_x = mlx->ray.plane_x;
	mlx->ray.plane_x = \
			mlx->ray.plane_x * cos(angle) - mlx->ray.plane_y * sin(angle);
	mlx->ray.plane_y = old_plane_x * sin(angle) + mlx->ray.plane_y * cos(angle);
}

void	move_forward(t_mlx *mlx)
{
	if (mlx->info.map[(int)(mlx->ray.pos_x + mlx->ray.dir_x * MOVE_SPEED)] \
				[(int)mlx->ray.pos_y] != '1')
		mlx->ray.pos_x += mlx->ray.dir_x * MOVE_SPEED;
	if (mlx->info.map[(int)mlx->ray.pos_x] \
				[(int)(mlx->ray.pos_y + mlx->ray.dir_y * MOVE_SPEED)] != '1')
		mlx->ray.pos_y += mlx->ray.dir_y * MOVE_SPEED;
}

void	move_backward(t_mlx *mlx)
{
	if (mlx->info.map[(int)(mlx->ray.pos_x - mlx->ray.dir_x * MOVE_SPEED)] \
				[(int)mlx->ray.pos_y] != '1')
		mlx->ray.pos_x -= mlx->ray.dir_x * MOVE_SPEED;
	if (mlx->info.map[(int)mlx->ray.pos_x] \
				[(int)(mlx->ray.pos_y - mlx->ray.dir_y * MOVE_SPEED)] != '1')
		mlx->ray.pos_y -= mlx->ray.dir_y * MOVE_SPEED;
}

void	move_left(t_mlx *mlx)
{
	if (mlx->info.map[(int)(mlx->ray.pos_x - mlx->ray.dir_y * MOVE_SPEED)] \
				[(int)mlx->ray.pos_y] != '1')
		mlx->ray.pos_x -= mlx->ray.dir_y * MOVE_SPEED;
	if (mlx->info.map[(int)mlx->ray.pos_x] \
				[(int)(mlx->ray.pos_y + mlx->ray.dir_x * MOVE_SPEED)] != '1')
		mlx->ray.pos_y += mlx->ray.dir_x * MOVE_SPEED;
}

void	move_right(t_mlx *mlx)
{
	if (mlx->info.map[(int)(mlx->ray.pos_x + mlx->ray.dir_y * MOVE_SPEED)] \
				[(int)mlx->ray.pos_y] != '1')
		mlx->ray.pos_x += mlx->ray.dir_y * MOVE_SPEED;
	if (mlx->info.map[(int)mlx->ray.pos_x] \
				[(int)(mlx->ray.pos_y - mlx->ray.dir_x * MOVE_SPEED)] != '1')
		mlx->ray.pos_y -= mlx->ray.dir_x * MOVE_SPEED;
}
