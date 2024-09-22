#include "cube.h"

int raycasting(t_cub *c)
{
	int	x;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		c->ray.camera_x = (2 * (x / (double)WINDOW_WIDTH)) - 1;
		c->ray.ray_dir[0] = c->player.v_dir[0] + (c->player.v_plane[0] * c->ray.camera_x);
		c->ray.ray_dir[1] =  c->player.v_dir[1] + (c->player.v_plane[1] * c->ray.camera_x);
		draw_vector(&c->img, c->player.position, c->ray.ray_dir, 100);
		x++;
	}
	return (0);
}