#include "libft.h"
#include <math.h>

# define MAX_ITER 150
# define ESC 53
# define SCROLL_UP 4
# define SCROLL_DOWN 5


typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}		t_ray;

typedef struct s_texture
{
	int		count_texture;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*c_color;
	char	*f_color;
}		t_texture;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	void		*mlx_img;
	char		*mlx_addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}		t_mlx;

typedef struct s_map
{
	char		*map_path;
	int			width;
	int			height;
	t_texture	*texture;
	t_ray		*ray;
}		t_map;

void	init(int argc, char *arg, t_map **map);
void	init_map(t_map **map, char *arg);

int	main(int argc, char **argv)
{
	t_map	*map;

	init(argc, argv[1], &map);
	map_parse(map);
	return (EXIT_SUCCESS);
}

void	init(int argc, char *arg, t_map **map)
{
	if (argc != 2)
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		ft_putstr_fd("Usage: ./cub3D <map_name.cub>\n", 2);
		exit(EXIT_FAILURE);
	}
	init_map(map, arg);
}

void	init_map(t_map **map, char *arg)
{
	*map = malloc(sizeof(t_map));
	if (!*map)
	{
		ft_putstr_fd("Malloc error\n", 2);
		exit(EXIT_FAILURE);
	}
	(*map)->path = get_map_path(arg);
	(*map)->width = 0;
	(*map)->height = 0;
	(*map)->texture = NULL;
	(*map)->ray = NULL;
}

