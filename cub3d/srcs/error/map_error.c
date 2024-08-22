#include "libft.h"

void	map_error_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	malloc_error(void)
{
	ft_putstr_fd("Malloc error\n", 2);
	exit(EXIT_FAILURE);
}