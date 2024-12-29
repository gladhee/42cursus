/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:36:14 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/13 21:42:07 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"
#include "mlx.h"
#include "const.h"

void	free_info(t_info *info);
void	free_tex_buf(t_mlx *mlx);
void	move_forward(t_mlx *mlx);
void	move_backward(t_mlx *mlx);
void	move_left(t_mlx *mlx);
void	move_right(t_mlx *mlx);
void	rotate_vec(t_mlx *mlx, double angle);

int	exit_press(t_mlx *mlx)
{
	free_info(&mlx->info);
	free_tex_buf(mlx);
	mlx_destroy_image(mlx->init, mlx->img.img);
	mlx_destroy_window(mlx->init, mlx->win);
	exit(0);
}

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC || keycode == 65307)
		exit (0);
	else if (keycode == KEY_W)
		mlx->key_w = TRUE;
	else if (keycode == KEY_A)
		mlx->key_a = TRUE;
	else if (keycode == KEY_S)
		mlx->key_s = TRUE;
	else if (keycode == KEY_D)
		mlx->key_d = TRUE;
	else if (keycode == KEY_LEFT)
		mlx->key_left = TRUE;
	else if (keycode == KEY_RIGHT)
		mlx->key_right = TRUE;
	return (TRUE);
}

int	key_release(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC || keycode == 65307)
		exit (0);
	else if (keycode == KEY_W)
		mlx->key_w = FALSE;
	else if (keycode == KEY_A)
		mlx->key_a = FALSE;
	else if (keycode == KEY_S)
		mlx->key_s = FALSE;
	else if (keycode == KEY_D)
		mlx->key_d = FALSE;
	else if (keycode == KEY_LEFT)
		mlx->key_left = FALSE;
	else if (keycode == KEY_RIGHT)
		mlx->key_right = FALSE;
	return (TRUE);
}

void	move_player(t_mlx *mlx)
{
	if (mlx->key_w)
		move_forward(mlx);
	if (mlx->key_s)
		move_backward(mlx);
	if (mlx->key_a)
		move_left(mlx);
	if (mlx->key_d)
		move_right(mlx);
	if (mlx->key_left)
		rotate_vec(mlx, ROTATE_SPEED);
	if (mlx->key_right)
		rotate_vec(mlx, -ROTATE_SPEED);
}
