/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 01:14:12 by anjansse          #+#    #+#             */
/*   Updated: 2019/09/07 01:22:31 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void			graphic_init(t_fractal *fractal)
{
	int		bpp;
	int		size;
	int		endian;

	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(MLX, SW, SH, "Fractal");
	fractal->ptr_img = mlx_new_image(MLX, SW, SH);
	fractal->img = (uint32_t*)mlx_get_data_addr(IMG, &bpp, &size, &endian);
	PARAM = 0;
}
