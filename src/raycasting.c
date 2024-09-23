#include "cube.h"

void	reset_ray(t_ray *r)
{
	r->ray_dir[0] = 0;
	r->ray_dir[1] = 0;
	r->camera_x = 0;
	r->map[0] = 0;
	r->map[1] = 0;
	r->delta_dist_x = 0;
	r->delta_dist_y = 0;
	r->side_dist_x = 0;
	r->side_dist_y = 0;
	r->step_x = 0;	
	r->step_y = 0;
	r->side = 0;
}

void	init_ray(t_cub *c, int x)
{
	reset_ray(&c->ray);
	c->ray.camera_x = (2 * (x / (double)WINDOW_WIDTH)) - 1;
	c->ray.camera_x = 0; //
	c->ray.ray_dir[0] = c->player.v_dir[0];// + (c->player.v_plane[0] * c->ray.camera_x);
	c->ray.ray_dir[1] =  c->player.v_dir[1];// + (c->player.v_plane[1] * c->ray.camera_x);
	// printf("ray_x; %f  ray_y; %f\n", c->ray.ray_dir[0], c->ray.ray_dir[1]);
	c->ray.map[0] = (int)c->player.position[0];
	c->ray.map[1] = (int)c->player.position[1];
	// printf("pos_x; %f  pos_y; %f  ", c->player.position[0], c->player.position[1]);
	// printf("map_x; %d  map_y; %d\n",c->ray.map[0], c->ray.map[1]);
	c->ray.delta_dist_x = fabs(1 / c->ray.ray_dir[0]);
	c->ray.delta_dist_y = fabs(1 / c->ray.ray_dir[1]);
	// printf("delta_x; %f  delta_y; %f\n", c->ray.delta_dist_x, c->ray.delta_dist_y);
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
	// printf("step_x; %d  step_y; %d\n", c->ray.step_x, c->ray.step_y);
	// printf("side_x; %f  side_y; %f\n", c->ray.side_dist_x, c->ray.side_dist_y);
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
		if (c->map.map[c->ray.map[0]][c->ray.map[1]] == 1)
		{
			printf("map_x; %d  map_y; %d  val; %d\n", c->ray.map[0], c->ray.map[1], c->map.map[c->ray.map[0]][c->ray.map[1]]);
			break;
		}
			
	}
	// if (c->ray.side == 0)
	// 	printf("dist_x; %f  ", c->ray.side_dist_x);
	// else
	// 	printf("dist_y; %f  ", c->ray.side_dist_y);
	// printf("map_x; %d  map_x; %d  val; %d\n", c->ray.map[0], c->ray.map[1], c->map.map[c->ray.map[0]][c->ray.map[1]]);	
}

int raycasting(t_cub *c)
{
	int	x;
	int size;

	x = 0;
	size = 0;
	while (x < 1)//WINDOW_WIDTH)
	{
		init_ray(c, x);
		
		calculating_initial_side_dist(c);

		calculating_ray_size(c);
		// printf("side_x; %f  side_y; %f\n", c->ray.side_dist_x, c->ray.side_dist_y);
		draw_vector(&c->img, c->player.position, c->ray.ray_dir, 100);

		// if (c->ray.side == 0)
		// 	draw_vector(&c->img, c->player.position, c->ray.ray_dir, c->ray.side_dist_x);
		// else
		// 	draw_vector(&c->img, c->player.position, c->ray.ray_dir, c->ray.side_dist_y);
		x++;
	}
	return (0);
}