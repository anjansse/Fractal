#include "fractal.h"

t_dis       g_dis_table[CMD] = {
	{"julia", &fractal_julia},
	{"mandel", &fractal_mandel},
	{"tricorn", &fractal_tricorn},
};

void		dispatcher(char **av, t_fractal *fractal)
{
	int		i;

	i = 0;
	while (i < CMD)
	{
		if (ft_strequ(av[0], g_dis_table[i].name))
		{
			g_dis_table[i].fractal(fractal);
			return ;
		}
		++i;
	}
	send_error("Error: Invalid fractal name");
}

void		fractal(char **av)
{
	t_fractal	fractal;

	graphic_init(&fractal);
	dispatcher(++av, &fractal);
	/*
	** Implement Mouse press, move and release then start going deeper with Julia.
	*/
	// mlx_hook(fractal.win, 2, 0, mouse_press, &game);
	// mlx_hook(fractal.win, 3, 0, mouse_release, &game);
	// mlx_loop_hook(game.mlx, display_map, &game);
	mlx_put_image_to_window(fractal.mlx, fractal.win, fractal.ptr_img, 0, 0);
	mlx_loop(fractal.mlx);
}

int         main(int ac, char *av[])
{
	if (ac != 2)
		send_error("Error: Invalid number of parameters\n\nusage: ./fractol <julia/mandel/wtf>\n");
	fractal(av);
	return (0);
}