/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:35:55 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/13 21:47:16 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include "const.h"
#include "raycaster.h"
#include "mlx.h"

t_bool	argc_error_exit(void);
t_bool	parse(t_info *info, char *filename);
void	free_info(t_info *info);
int		run(t_mlx *mlx);
void	init_ray(t_mlx *mlx);
t_bool	init_mlx(t_mlx *mlx);
void	load_image(t_mlx *mlx);
void	free_tex_buf(t_mlx *mlx);
void	first_run(t_mlx *mlx);

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	ft_memset(&mlx, 0, sizeof(t_mlx));
	if (argc != 2)
		return (argc_error_exit());
	if (!parse(&(mlx.info), argv[1]))
		return (EXIT_FAILURE);
	if (!init_mlx(&mlx))
		return (EXIT_FAILURE);
	load_image(&mlx);
	init_ray(&mlx);
	first_run(&mlx);
	mlx_loop_hook(mlx.init, &run, &mlx);
	mlx_loop(mlx.init);
	free_info(&mlx.info);
	free_tex_buf(&mlx);
	return (EXIT_SUCCESS);
}
