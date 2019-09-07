/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 01:13:03 by anjansse          #+#    #+#             */
/*   Updated: 2019/09/07 01:20:15 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int				key_press(int key, void *param)
{
	t_fractal *fractal;

	fractal = ((t_fractal*)param);
	if (key == ESC)
		quit_program(fractal);
	else if (key == PLUS)
		ZOOM = (ZOOM * 2) % 2147483647;
	else if (key == MINUS)
		ZOOM = ZOOM / 2;
	else if (key == ARROW_RIGHT)
		MOVEX += 0.02;
	else if (key == ARROW_LEFT)
		MOVEX -= 0.02;
	else if (key == ARROW_UP)
		MOVEY -= 0.02;
	else if (key == ARROW_DOWN)
		MOVEY += 0.02;
	else if (key == SPACE)
		PARAM = (PARAM == 1) ? 0 : 1;
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
		ZOOM = (ZOOM * 2) % 2147483647;
	else if (button == ZOOM_OU)
		ZOOM = (ZOOM / 2 < 1.0) ? 1.0 : ZOOM / 2;
	return (0);
}

int				mouse_move(int x, int y, void *param)
{
	t_fractal *fractal;

	fractal = ((t_fractal*)param);
	if (PARAM == 0)
	{
		CI += (double)(x * 0.00001);
		CR -= (double)(y * 0.00001);
	}
	else if (PARAM == 1)
	{
		CI -= (double)(x * 0.0001);
		CR += (double)(y * 0.0001);
	}
	return (0);
}
