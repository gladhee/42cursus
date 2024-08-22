#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

# define MAP_DIR "maps/"
# define

void	map_error_exit(char *msg);
void	malloc_error(void);

char	*get_map_path(char *arg)
{
	char	*map_path;

	if (!is_valid_map_name(arg))
		map_error_exit("Invalid map name\n");
	map_path = ft_strjoin(MAP_DIR, arg);
	if (!map_path)
		malloc_error();
	return (map_path);
}
