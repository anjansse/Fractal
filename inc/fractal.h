#ifndef     FRACTAL_H
# define    FRACTAL_H

# include   "../libft/includes/libft.h"
# include "../Minilibx/minilibx_macos/mlx.h"
# include   <math.h>

# define    CMD     2
# define	SH		800
# define	SW		1500

typedef struct		s_julia
{
	int				zoom;
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

void			graphic_init(t_fractal *fractal);

void            fractal_julia(t_fractal *fractal);

void            fractal_mandel(t_fractal *fractal);

#endif