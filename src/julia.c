#include "fractal.h"

static int			fractal_display_julia(t_fractal *fractal)
{
	double		zx;
	double		zy;
	double		cx;
	double		cy;
	double		moveX;
	double		moveY;
	double		tmp;
	int			maxIter;
	int			i;
	int			x;
	int			y;

	y = 0;
	maxIter = 255;
	moveX = 1.0;
	moveY = 0.0;
	cx = -0.7;
	cy = 0.27015;
	while (y < SH)
	{
		x = 0;
		while (x < SW)
		{
			zx = 1.5 * (x - SW/2) / (0.5 * fractal->julia.zoom * SW) + moveX;
			zy = 1.0 * (y - SH/2) / (0.5 * fractal->julia.zoom * SH) + moveY;
			i = maxIter;
			while (zx * zx + zy * zy < 4 && i > 1)
			{ 
				tmp = zx * zx - zy * zy + cx;
				zx = 2.0 * zx * zy + cy + tmp;
				zy = 2.0 * zx * zy + cy + tmp;
				--i;
				fractal->img[y * SW + x] = (i << 21) + (i << 10) + i * 8;
			}
			++x;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->ptr_img, 0, 0);
	return (0);
}

void				fractal_julia(t_fractal *fractal)
{
	fractal->julia.zoom = 1;
	mlx_hook(fractal->win, 2, 0, key_press, fractal);
	mlx_hook(fractal->win, 4, 0, mouse_press, fractal);
	mlx_hook(fractal->win, 5, 0, mouse_release, fractal);
	mlx_hook(fractal->win, 6, 0, mouse_move, fractal);
    mlx_loop_hook(fractal->mlx, fractal_display_julia, fractal);
	mlx_loop(fractal->mlx);
}