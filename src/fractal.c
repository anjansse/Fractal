/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 01:13:28 by anjansse          #+#    #+#             */
/*   Updated: 2019/09/07 01:21:45 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_dis		g_dis_table[CMD] = {
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
	send_error("Error: Invalid fractal name\n\nusage: ./fractol \
			<julia/mandel/tricorn>\n");
}

void		fractal(char **av)
{
	t_fractal	fractal;

	graphic_init(&fractal);
	dispatcher(++av, &fractal);
	mlx_put_image_to_window(fractal.mlx, fractal.win, fractal.ptr_img, 0, 0);
	mlx_loop(fractal.mlx);
}

int			main(int ac, char *av[])
{
	if (ac != 2)
		send_error("Error: Invalid number of parameters\n\nusage: ./fractol \
				<julia/mandel/tricorn>\n");
	fractal(av);
	return (0);
}
