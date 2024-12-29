/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:36:12 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/13 21:36:12 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"
#include "const.h"
#include "libft.h"

void	set_pos(t_mlx *mlx);
void	set_dir(t_mlx *mlx);
void	free_words(char **words);
int		get_color_int(char *color);
void	set_buf(t_mlx *mlx);

void	init_ray(t_mlx *mlx)
{
	mlx->ray.pos_x = 0;
	mlx->ray.pos_y = 0;
	mlx->ray.dir_x = 0;
	mlx->ray.dir_y = 0;
	mlx->ray.plane_x = 0;
	mlx->ray.plane_y = 0;
	mlx->f_color = get_color_int(mlx->info.ident.f_color);
	mlx->c_color = get_color_int(mlx->info.ident.c_color);
	set_pos(mlx);
	set_dir(mlx);
	set_buf(mlx);
}

void	set_pos(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->info.map[i])
	{
		j = 0;
		while (mlx->info.map[i][j])
		{
			if (ft_strchr(CARDINAL_DIR, mlx->info.map[i][j]))
			{
				mlx->ray.pos_x = i;
				mlx->ray.pos_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	set_dir(t_mlx *mlx)
{
	char	dir;

	dir = mlx->info.map[(int)mlx->ray.pos_x][(int)mlx->ray.pos_y];
	if (dir == 'N')
	{
		mlx->ray.dir_x = -1;
		mlx->ray.plane_y = 0.66;
	}
	else if (dir == 'S')
	{
		mlx->ray.dir_x = 1;
		mlx->ray.plane_y = -0.66;
	}
	else if (dir == 'W')
	{
		mlx->ray.dir_y = -1;
		mlx->ray.plane_x = -0.66;
	}
	else if (dir == 'E')
	{
		mlx->ray.dir_y = 1;
		mlx->ray.plane_x = 0.66;
	}
	mlx->ray.pos_x += 0.5;
	mlx->ray.pos_y += 0.5;
}

void	set_buf(t_mlx *mlx)
{
	int	i;

	i = -1;
	mlx->buf = (int **)ft_calloc(sizeof(int *) * WINDOW_HEIGHT, 1);
	if (!mlx->buf)
		put_error_exit("mlx->buf malloc failed");
	while (++i < WINDOW_HEIGHT)
	{
		mlx->buf[i] = (int *)ft_calloc(sizeof(int) * WINDOW_WIDTH, 1);
		if (!mlx->buf[i])
			put_error_exit("mlx->buf[i] malloc failed");
	}
}

int	get_color_int(char *color)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	split = ft_split(color, ',');
	if (!split)
		put_error_exit("Malloc\n");
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	free_words(split);
	return (r << 16 | g << 8 | b);
}
