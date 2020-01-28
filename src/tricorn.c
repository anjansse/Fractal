/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 01:19:43 by anjansse          #+#    #+#             */
/*   Updated: 2019/09/07 12:08:53 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void			init_tricorn(t_fractal *fractal)
{
	NEWRE = 0.0;
	NEWIM = 0.0;
	OLDRE = 0.0;
	OLDIM = 0.0;
}

static void			fractal_loop(t_fractal *fractal, int x, int y, int i)
{
	while (NEWRE * NEWRE + NEWIM * NEWIM < 4 && i > 1)
	{
		OLDRE = NEWRE;
		OLDIM = NEWIM;
		NEWRE = fabs(2.0 * OLDRE * OLDIM) + CR;
		NEWIM = fabs(OLDRE * OLDRE - OLDIM * OLDIM + CI);
		--i;
		fractal->img[y * SW + x] = (i << 19) + (i << 9) + i * 8;
	}
}

static int			fractal_display_tricorn(t_fractal *fractal)
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
			CR = 1.5 * (x - SW / 2) / (0.5 * ZOOM * SW) + MOVEX;
			CI = 1.0 * (y - SH / 2) / (0.5 * ZOOM * SH) + MOVEY;
			i = max_iter;
			init_tricorn(fractal);
			fractal_loop(fractal, x, y, i);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (0);
}

void				fractal_tricorn(t_fractal *fractal)
{
	MOVEX = 0.0;
	MOVEY = 0.0;
	ZOOM = 1;
	init_tricorn(fractal);
	mlx_hook(WIN, 2, 0, key_press, fractal);
	mlx_hook(WIN, 4, 0, mouse_press, fractal);
	mlx_hook(WIN, 6, 0, mouse_move, fractal);
	mlx_loop_hook(MLX, fractal_display_tricorn, fractal);
	mlx_loop(MLX);
	(void)fractal;
}
