/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 01:13:21 by anjansse          #+#    #+#             */
/*   Updated: 2019/09/07 01:21:00 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		send_error(char *error)
{
	ft_putstr(RED);
	ft_putstr(BOLD);
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
