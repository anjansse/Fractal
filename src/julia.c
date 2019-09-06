#include "fractal.h"

void            fractal_julia(t_fractal *fractal)
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
	moveX = 0.0;
	moveY = 0.0;
	cx = -0.7;
	cy = 0.27015;
	fractal->julia.zoom = 1;
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
}