/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:24:07 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/15 20:24:08 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"
#include "const.h"
#include "mlx.h"

void	raycasting(t_mlx *mlx);
void	draw(t_mlx *mlx);
void	move_player(t_mlx *mlx);
void	set_ray(t_mlx *mlx, t_calc *calc, int x);
void	init_dda(t_mlx *mlx, t_calc *calc);
void	perform_dda(t_mlx *mlx, t_calc *calc);
void	calculate_wall(t_mlx *mlx, t_calc *calc);
void	draw_wall(t_mlx *mlx, t_calc *calc, int x);
t_bool	check_event(t_mlx *mlx);

void	first_run(t_mlx *mlx)
{
	raycasting(mlx);
	draw(mlx);
	move_player(mlx);
}

int	run(t_mlx *mlx)
{
	if (!check_event(mlx))
		return (0);
	raycasting(mlx);
	draw(mlx);
	move_player(mlx);
	return (0);
}

t_bool	check_event(t_mlx *mlx)
{
	if (mlx->key_a)
		return (TRUE);
	if (mlx->key_s)
		return (TRUE);
	if (mlx->key_d)
		return (TRUE);
	if (mlx->key_w)
		return (TRUE);
	if (mlx->key_left)
		return (TRUE);
	if (mlx->key_right)
		return (TRUE);
	return (FALSE);
}

void	raycasting(t_mlx *mlx)
{
	t_calc	calc;
	int		x;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		set_ray(mlx, &calc, x);
		init_dda(mlx, &calc);
		perform_dda(mlx, &calc);
		calculate_wall(mlx, &calc);
		draw_wall(mlx, &calc, x);
		x++;
	}
}

void	draw(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			mlx->img.data[y * WINDOW_WIDTH + x] = mlx->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img.img, 0, 0);
}
