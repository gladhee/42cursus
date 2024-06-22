/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:32:25 by heechoi           #+#    #+#             */
/*   Updated: 2024/05/22 11:35:19 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractol_info(void)
{
	ft_putstr_fd("Usage: ./fractol [fractal]\n", 2);
	ft_putstr_fd("Available fractals: mandelbrot, julia 0.xxx 0.xxx\n", 2);
	exit(EXIT_FAILURE);
}

void	error_exit(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
