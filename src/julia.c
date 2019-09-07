/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 01:22:49 by anjansse          #+#    #+#             */
/*   Updated: 2019/09/07 01:23:44 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void			init_julia(t_fractal *fractal)
{
	MOVEX = 0.0;
	MOVEY = 0.0;
	CR = -0.7;
	CI = 0.27015;
	ZOOM = 1;
}

static void			fractal_loop(t_fractal *fractal, int x, int y, int i)
{
	while (NEWRE * NEWRE + NEWIM * NEWIM < 4 && i > 1)
	{
		OLDRE = NEWRE;
		OLDIM = NEWIM;
		NEWRE = OLDRE * OLDRE - OLDIM * OLDIM + CR;
		NEWIM = 2 * OLDRE * OLDIM + CI;
		--i;
		fractal->img[y * SW + x] = (i << 21) + (i << 10) + i * 8;
	}
}

static int			fractal_display_julia(t_fractal *fractal)
{
	int			max_iter;
	int			i;
	int			x;
	int			y;

	y = 0;
	max_iter = 255;
	while (y < SH)
	{
		x = 0;
		while (x < SW)
		{
			NEWRE = 1.5 * (x - SW / 2) / (0.5 * ZOOM * SW) + MOVEX;
			NEWIM = 1.0 * (y - SH / 2) / (0.5 * ZOOM * SH) + MOVEY;
			i = max_iter;
			fractal_real_imaginary_loop(fractal, x, y, i);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (0);
}

void				fractal_julia(t_fractal *fractal)
{
	init_julia(fractal);
	mlx_hook(WIN, 2, 0, key_press, fractal);
	mlx_hook(WIN, 4, 0, mouse_press, fractal);
	mlx_hook(WIN, 6, 0, mouse_move, fractal);
	mlx_loop_hook(MLX, fractal_display_julia, fractal);
	mlx_loop(MLX);
}
