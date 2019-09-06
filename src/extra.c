#include "fractal.h"

void        send_error(char *error)
{
	ft_putstr(RED BOLD);
	ft_putstr(error);
	ft_putstr(RESET);
	exit(1);
}

void		quit_program(t_fractal *fractal)
{
	mlx_clear_window(fractal->mlx, fractal->win);
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(0);
}
