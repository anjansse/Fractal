#include "fractal.h"

void        send_error(char *error)
{
	ft_putstr(RED BOLD);
	ft_putstr(error);
	ft_putstr(RESET);
	exit(1);
}
