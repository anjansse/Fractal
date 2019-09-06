#include "fractal.h"

void           graphic_init(t_fractal *fractal)
{
	int		bpp;
	int		size;
	int		endian;

	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx, SW, SH, "Fractal");
	fractal->ptr_img = mlx_new_image(fractal->mlx, SW, SH);
	fractal->img = (uint32_t*)mlx_get_data_addr(fractal->ptr_img, &bpp, &size, &endian);
}