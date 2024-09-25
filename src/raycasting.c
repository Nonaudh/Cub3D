#include "cube.h"


void	init_ray(t_cub *c, int x)
{
	c->ray.camera_x = (2 * (x / (double)WINDOW_WIDTH)) - 1;
	c->ray.ray_dir[0] = c->player.v_dir[0] + (c->player.v_plane[0] * c->ray.camera_x);
	c->ray.ray_dir[1] =  c->player.v_dir[1] + (c->player.v_plane[1] * c->ray.camera_x);
	c->ray.map[0] = (int)c->player.position[0];
	c->ray.map[1] = (int)c->player.position[1];
	c->ray.delta_dist_x = fabs(1 / c->ray.ray_dir[0]);
	c->ray.delta_dist_y = fabs(1 / c->ray.ray_dir[1]);
}

void	calculating_initial_side_dist(t_cub *c)
{
	if (c->ray.ray_dir[0] < 0)
	{
		c->ray.step_x = -1;
		c->ray.side_dist_x = (c->player.position[0] - c->ray.map[0]) * c->ray.delta_dist_x;
	}
	else
	{
		c->ray.step_x = 1;
		c->ray.side_dist_x = (c->ray.map[0] + 1.0 - c->player.position[0]) * c->ray.delta_dist_x;
	}
	if (c->ray.ray_dir[1] < 0)
	{
		c->ray.step_y = -1;
		c->ray.side_dist_y = (c->player.position[1] - c->ray.map[1]) * c->ray.delta_dist_y;
	}
	else
	{
		c->ray.step_y = 1;
		c->ray.side_dist_y = (c->ray.map[1] + 1.0 - c->player.position[1]) * c->ray.delta_dist_y;
	}
}

void calculating_ray_size(t_cub *c)
{
	while (1)
	{
		if (c->ray.side_dist_x < c->ray.side_dist_y)
		{
			c->ray.side_dist_x += c->ray.delta_dist_x;
			c->ray.map[0] += c->ray.step_x;
			c->ray.side = 0;
		}
		else
		{
			c->ray.side_dist_y += c->ray.delta_dist_y;
			c->ray.map[1] += c->ray.step_y;
			c->ray.side = 1;			
		}
		if (c->map.map[c->ray.map[1]][c->ray.map[0]] == 1)
			break;
	}
}

int raycasting(t_cub *c)
{
	int	x;
	int size;

	x = 0;
	size = 0;
	while (x < WINDOW_WIDTH)
	{
		init_ray(c, x);
		
		calculating_initial_side_dist(c);

		calculating_ray_size(c);

		draw_line(c, x);

		x++;
	}
	return (0);
}