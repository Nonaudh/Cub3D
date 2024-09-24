#ifndef ARNAUD_H
# define ARNAUD_H

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define PI 3.1415926535

# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_player
{
	double	position[2];
	double dir_angle;
	double v_dir[2];
	double v_plane[2];
	int		fov;
}	t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_window;
}	t_mlx;

typedef struct s_map
{
	int		**map;
	int		map_width;
	int		map_height;
	int		square_lenght;
}	t_map;

typedef struct s_ray
{
	double	ray_dir[2];
	double	camera_x;
	int		map[2];
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
}	t_ray;

typedef struct s_line
{
	double	perp_wall_dist;
	double	line_height;
	double	draw_start;
	double	draw_end;
	int		celling_color;
	int		floor_color;
}	t_line;

typedef struct s_cub
{
	t_mlx		mlx;
	t_img		img;
	t_player	player;
	t_map		map;
	t_ray		ray;
	t_line		line;
}	t_cub;

void	draw_map(t_img *img, t_map *map);
void	set_screen_to_grey(t_img* img);
void	draw_player(t_img *img, double pos[2]);
void	draw_vector(t_img *img, double origin[2], double dir[2], int size);

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

void	move_player(t_player *p, int keysym, double size);

void	rotate_player(t_player *p, double size);

int		raycasting(t_cub *c);

void	draw_line(t_cub *c, int x);

#endif