#include "fractal.h"

int				key_press(int key, void	*param)
{
	t_fractal *fractal;

	fractal = ((t_fractal*)param);
	if (key == ESC)
		quit_program(fractal);
	return (0);
}

int				mouse_press(int button, int x, int y, void *param)
{
	t_fractal *fractal;

	fractal = ((t_fractal*)param);
	(void)x;
	(void)y;
	(void)fractal;
	if (button == ZOOM_IN)
		fractal->julia.zoom += 1;
	else if (button == ZOOM_OU)
		fractal->julia.zoom = ((fractal->julia.zoom - 1) >= 1) ? fractal->julia.zoom - 1 : 1;
	return (0);
}

int				mouse_release(int button, int x, int y, void *param)
{
	t_fractal *fractal;

	fractal = ((t_fractal*)param);
	(void)x;
	(void)y;
	(void)button;
	(void)fractal;
	return (0);
}

int				mouse_move(int x, int y, void *param)
{
	t_fractal *fractal;

	fractal = ((t_fractal*)param);
	fractal->julia.moveX = (double)(x * 0.0001);
	fractal->julia.moveY = (double)(y * 0.0001);
	printf("(%d, %d)", x, y);
	return (0);
}