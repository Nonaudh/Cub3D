#include "cube.h"

void	define_side_floor(t_data *data, int x)
{
	if ((data->ray->side == EAST || data->ray->side == WEST) && data->ray->ray_dir[0] > 0)
	{
		data->line->floor_x_wall = data->ray->map[0];
		data->line->floor_y_wall = data->ray->map[1] + data->line->wall_x;
	}
	else if ((data->ray->side == EAST || data->ray->side == WEST) && data->ray->ray_dir[0] < 0)
	{
		data->line->floor_x_wall = data->ray->map[0] + 1.0;
		data->line->floor_y_wall = data->ray->map[1] + data->line->wall_x;
	}
	else if ((data->ray->side == NORTH || data->ray->side == SOUTH) && data->ray->ray_dir[1] > 0)
	{
		data->line->floor_x_wall = data->ray->map[0] + data->line->wall_x;
		data->line->floor_y_wall = data->ray->map[1];
	}
	else if ((data->ray->side == NORTH  || data->ray->side == SOUTH) && data->ray->ray_dir[1] < 0)
	{
		data->line->floor_x_wall = data->ray->map[0] + data->line->wall_x;
		data->line->floor_y_wall = data->ray->map[1] + 1.0;
	}
}

void	init_data_floor(t_data *data, int x)
{
	data->line->dist_wall = data->line->perp_wall_dist;
	data->line->dist_player  = 0.0;
	if (data->line->draw_end < 0)
		data->line->draw_end = M_H;
}

void	pixel_textured_floor(t_data *data,	int x, int y, double floor_tex[2])
{
	int	color[2];

	color[0] = ft_get_pixel_img(data->line->texture[4], floor_tex[0], floor_tex[1]);
	color[1] = ft_get_pixel_img(data->line->texture[5], floor_tex[0], floor_tex[1]);
	my_mlx_pixel_put(data->img, x, y, color[0]);
	my_mlx_pixel_put(data->img, x, M_H - y, color[1]);
}

void	draw_textures_floor_celling(t_data *data, int x)
{
	int	y;
	double	weight;
	double	current_floor[2];
	double	floor_tex[2];

	y = data->line->draw_end + 1;
	while (y < M_H)
	{
		data->line->current_dist = M_H / (2.0 * y - M_H);
		weight = (data->line->current_dist - data->line->dist_player) / (data->line->dist_wall - data->line->dist_player);
		current_floor[0] = weight * data->line->floor_x_wall + (1.0 - weight) * data->player.position[0];
		current_floor[1] = weight * data->line->floor_y_wall + (1.0 - weight) * data->player.position[1];
		floor_tex[0] = (int)(current_floor[0] * TEX_WIDTH) % TEX_WIDTH;
		floor_tex[1] = (int)(current_floor[1] * TEX_HEIGHT) % TEX_HEIGHT;
		pixel_textured_floor(data, x, y, floor_tex);
		y++;
	}
}

void	draw_floor_celling(t_data *data, int x)
{
	define_side_floor(data, x);
	init_data_floor(data, x);
	draw_textures_floor_celling(data, x);
}