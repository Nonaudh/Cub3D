#include "cube.h"

double	calculate_perp_wall_dist(t_cub *c)
{
	if (c->ray.side == 0)
		return (c->ray.side_dist_x - c->ray.delta_dist_x);
	else
		return (c->ray.side_dist_y - c->ray.delta_dist_y);
}

void	init_line(t_cub *c)
{
	c->line.celling_color = 0x003FC1C9;
	c->line.floor_color = 0x00F5F5F5;
	c->line.perp_wall_dist = calculate_perp_wall_dist(c);
	c->line.line_height = (WINDOW_HEIGHT / c->line.perp_wall_dist);
	c->line.draw_start = -c->line.line_height / 2 + WINDOW_HEIGHT / 2;
	if (c->line.draw_start < 0)
		c->line.draw_start = 0;
	c->line.draw_end = c->line.line_height / 2 + WINDOW_HEIGHT / 2;
	if (c->line.draw_end >= WINDOW_HEIGHT)
		c->line.draw_end = WINDOW_HEIGHT - 1;
}

void	pixel_line(t_cub *c, int x)
{
	int	i;

	i = 0;
	while (i < c->line.draw_start)
	{
		my_mlx_pixel_put(&c->img, x, i, c->line.celling_color);
		i++;
	}
	while (i < c->line.draw_end)
	{
		if (c->ray.side)
			my_mlx_pixel_put(&c->img, x, i, 0x00FC5185);
		else
			my_mlx_pixel_put(&c->img, x, i, 0x00364F6B);
		i++;
	}
	while (i < WINDOW_HEIGHT - 1)
	{
		my_mlx_pixel_put(&c->img, x, i, c->line.floor_color);
		i++;
	}
}


void	draw_line(t_cub *c, int x)
{
	init_line(c);
	pixel_line(c, x);
	// if (x == WINDOW_WIDTH / 2)
	// 	printf("perp; %f  start; %f  end; %f\n", c->line.perp_wall_dist, c->line.draw_start, c->line.draw_end);
}
