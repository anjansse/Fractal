#ifndef     FRACTAL_H
# define    FRACTAL_H

# include   "../libft/includes/libft.h"
# include "../Minilibx/minilibx_macos/mlx.h"
# include   <math.h>

/*
** @CMD -> number of Fractol available for dispatch table.
** @SH 	-> Screen Heigth.
** @SW 	-> Screen Width.
*/

# define    CMD     3
# define	SH		400
# define	SW		700

/*
** List of keys macros.
*/

# define 	ESC		53
# define 	ZOOM_IN	4
# define	ZOOM_OU	5

/*
** List of macros to make the algos easier to read.
*/

# define 	NEWRE	fractal->julia.zx
# define 	NEWIM	fractal->julia.zy
# define	OLDRE	fractal->julia.tmpzx
# define	OLDIM	fractal->julia.tmpzy
# define	CR		fractal->julia.cx
# define	CI		fractal->julia.cy
# define 	ZOOM	fractal->julia.zoom
# define 	MOVEX	fractal->julia.moveX
# define	MOVEY	fractal->julia.moveY

typedef struct		s_julia
{
	int				zoom;
	double			zx;
	double			zy;
	double			cx;
	double			cy;
	double			moveX;
	double			moveY;
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
}					t_fractal;

typedef void		(t_fractal_disp)(t_fractal*);

typedef struct		s_dis {
	char			*name;
	t_fractal_disp	*fractal;
}					t_dis;

void            send_error(char *error);
void			quit_program(t_fractal *fractal);

void			graphic_init(t_fractal *fractal);
int				key_press(int key, void	*param);
int				mouse_press(int button, int x, int y, void *param);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);

void            fractal_julia(t_fractal *fractal);
void            fractal_tricorn(t_fractal *fractal);
void            fractal_mandel(t_fractal *fractal);

#endif