/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:36:23 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/13 21:39:42 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"
#include "mlx.h"
#include "const.h"
#include "libft.h"

void	free_words(char **words);
int		get_color_int(char *color);

void	calculate_wall(t_mlx *mlx, t_calc *calc)
{
	calc->line_height = (int)(WINDOW_HEIGHT / calc->perp_wall_dist);
	calc->draw_start = -calc->line_height / 2 + WINDOW_HEIGHT / 2;
	if (calc->draw_start < 0)
		calc->draw_start = 0;
	calc->draw_end = calc->line_height / 2 + WINDOW_HEIGHT / 2;
	if (calc->draw_end >= WINDOW_HEIGHT)
		calc->draw_end = WINDOW_HEIGHT - 1;
	if (calc->ray_dir_x > 0 && calc->side == 0)
		calc->tex_num = NO;
	else if (calc->ray_dir_x < 0 && calc->side == 0)
		calc->tex_num = SO;
	else if (calc->ray_dir_y > 0 && calc->side == 1)
		calc->tex_num = WE;
	else
		calc->tex_num = EA;
	if (calc->side == 0)
		calc->wall_x = mlx->ray.pos_y + calc->perp_wall_dist * calc->ray_dir_y;
	else
		calc->wall_x = mlx->ray.pos_x + calc->perp_wall_dist * calc->ray_dir_x;
	calc->wall_x -= floor(calc->wall_x);
	calc->tex_x = (int)(calc->wall_x * (double)TEXTURE_WIDTH);
	if (calc->side == 0 && calc->ray_dir_x > 0)
		calc->tex_x = TEXTURE_WIDTH - calc->tex_x - 1;
	if (calc->side == 1 && calc->ray_dir_y < 0)
		calc->tex_x = TEXTURE_WIDTH - calc->tex_x - 1;
}

void	draw_wall(t_mlx *mlx, t_calc *calc, int x)
{
	int	y;
	int	color;

	calc->step = 1.0 * TEXTURE_HEIGHT / calc->line_height;
	calc->tex_pos = (calc->draw_start - (double)WINDOW_HEIGHT / 2 \
					+ (double)calc->line_height / 2) * calc->step;
	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		if (y >= calc->draw_start && y <= calc->draw_end)
		{
			calc->tex_y = (int)calc->tex_pos & (TEXTURE_HEIGHT - 1);
			calc->tex_pos += calc->step;
			color = mlx->texture[calc->tex_num] \
						[TEXTURE_HEIGHT * calc->tex_y + calc->tex_x];
			if (calc->side == 1)
				color = (color >> 1) & 8355711;
			mlx->buf[y][x] = color;
		}
		else if (y < calc->draw_start)
			mlx->buf[y][x] = mlx->c_color;
		else
			mlx->buf[y][x] = mlx->f_color;
	}
}
