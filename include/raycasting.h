#ifndef RAYCASTING_H
# define RAYCASTING_H

typedef struct s_cub t_cub;

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

int 	raycasting(t_cub *c);
void 	calculating_ray_size(t_cub *c);
void    calculating_initial_side_dist(t_cub *c);
void    init_ray(t_cub *c, int x);

# endif