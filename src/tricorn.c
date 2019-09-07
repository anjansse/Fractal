#include "fractal.h"

static void			init_tricorn(t_fractal *fractal)
{
	NEWRE = 0.0;
	NEWIM = 0.0;
	OLDRE = 0.0;
	OLDIM = 0.0;
}

static void			fractal_real_imaginary_loop(t_fractal *fractal, int x, int y, int i)
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

static int     fractal_display_tricorn(t_fractal *fractal)
{
	int			maxIter;
	int			i;
	int			x;
	int			y;

	y = 0;
	maxIter = 255;
	while (y < SH)
	{
		x = 0;
		while (x < SW)
		{
			CR = 1.5 * (x - SW/2) / (0.5 * ZOOM * SW) + MOVEX;
			CI = 1.0 * (y - SH/2) / (0.5 * ZOOM * SH) + MOVEY;
			i = maxIter;
			init_tricorn(fractal);
			fractal_real_imaginary_loop(fractal, x, y, i);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->ptr_img, 0, 0);
	return (0);
}

void            fractal_tricorn(t_fractal *fractal)
{
    MOVEX = -0.5;
	MOVEY = 0.0;
	ZOOM = 1;
	init_tricorn(fractal);
	mlx_hook(fractal->win, 2, 0, key_press, fractal);
	mlx_hook(fractal->win, 4, 0, mouse_press, fractal);
	mlx_hook(fractal->win, 5, 0, mouse_release, fractal);
	mlx_hook(fractal->win, 6, 0, mouse_move, fractal);
	mlx_loop_hook(fractal->mlx, fractal_display_tricorn, fractal);
	mlx_loop(fractal->mlx);
	(void)fractal;
}