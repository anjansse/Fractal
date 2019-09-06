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
	printf("pressed button : %d\n", button);
	return (0);
}

int				mouse_release(int button, int x, int y, void *param)
{
	t_fractal *fractal;

	fractal = ((t_fractal*)param);
	(void)x;
	(void)y;
	(void)fractal;
	printf("released button : %d\n", button);
	return (0);
}

int				mouse_move(int x, int y, void *param)
{
	t_fractal *fractal;

	fractal = ((t_fractal*)param);
	(void)x;
	(void)y;
	(void)fractal;
	return (0);
}