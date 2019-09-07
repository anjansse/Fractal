/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 01:25:54 by anjansse          #+#    #+#             */
/*   Updated: 2019/09/07 01:33:24 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "../libft/includes/libft.h"
# include "../Minilibx/minilibx_macos/mlx.h"
# include <math.h>

/*
** @CMD -> number of Fractol available for dispatch table.
** @SH  -> Screen Heigth.
** @SW  -> Screen Width.
*/

# define CMD			3
# define SH				550
# define SW				900

/*
** List of keys macros.
*/

# define ESC			53
# define ZOOM_IN		4
# define ZOOM_OU		5
# define PLUS			24
# define SPACE			49
# define MINUS			27
# define ARROW_UP		126
# define ARROW_DOWN		125
# define ARROW_RIGHT	124
# define ARROW_LEFT		123

/*
** List of macros to make the algos easier to read.
*/

# define MLX			fractal->mlx
# define WIN			fractal->win
# define IMG			fractal->ptr_img
# define NEWRE			fractal->julia.zx
# define NEWIM			fractal->julia.zy
# define OLDRE			fractal->julia.tmpzx
# define OLDIM			fractal->julia.tmpzy
# define CR				fractal->julia.cx
# define CI				fractal->julia.cy
# define ZOOM			fractal->julia.zoom
# define MOVEX			fractal->julia.movex
# define MOVEY			fractal->julia.movey
# define PARAM			fractal->param

typedef struct		s_julia
{
	unsigned int	zoom;
	double			zx;
	double			zy;
	double			cx;
	double			cy;
	double			movex;
	double			movey;
	double			tmpzx;
	double			tmpzy;
}					t_julia;

typedef struct		s_fractal
{
	void			*mlx;
	void			*win;
	void			*ptr_img;
	uint32_t		*img;
	t_julia			julia;
	unsigned char	param;
}					t_fractal;

typedef void		(t_fractal_disp)(t_fractal*);

typedef struct		s_dis {
	char			*name;
	t_fractal_disp	*fractal;
}					t_dis;

void				send_error(char *error);
void				quit_program(t_fractal *fractal);

void				graphic_init(t_fractal *fractal);
int					key_press(int key, void	*param);
int					mouse_press(int button, int x, int y, void *param);
int					mouse_move(int x, int y, void *param);

void				fractal_julia(t_fractal *fractal);
void				fractal_tricorn(t_fractal *fractal);
void				fractal_mandel(t_fractal *fractal);

#endif
