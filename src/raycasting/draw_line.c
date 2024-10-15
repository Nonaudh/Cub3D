/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:05:21 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/30 16:12:54 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_line.h"
#include "graph.h"

double	calculate_perp_wall_dist(t_data *data)
{
	if (data->ray->side == EAST || data->ray->side == WEST)
		return (data->ray->side_dist_x - data->ray->delta_dist_x);
	else
		return (data->ray->side_dist_y - data->ray->delta_dist_y);
}

void	init_tex_line(t_data *data)
{
	data->line->tex_num = data->ray->side;
	if (data->ray->side == EAST || data->ray->side == WEST)
		data->line->wall_x = data->player.position[1] + data->line->perp_wall_dist * data->ray->ray_dir[1];
	else
		data->line->wall_x = data->player.position[0] + data->line->perp_wall_dist * data->ray->ray_dir[0];
	data->line->wall_x -= floor(data->line->wall_x);
	data->line->tex_x = (int)(data->line->wall_x * (double)(TEX_WIDTH));
	if ((data->ray->side == EAST || data->ray->side == WEST) && data->ray->ray_dir[0] > 0)
		data->line->tex_x = TEX_WIDTH - data->line->tex_x - 1;
	if ((data->ray->side == SOUTH || data->ray->side == NORTH) && data->ray->ray_dir[1] < 0)
		data->line->tex_x = TEX_WIDTH - data->line->tex_x - 1;
}

void	init_line(t_data *data)
{
	data->line->ceiling_color = get_color(1, data->map.ceiling[0],
			data->map.ceiling[1], data->map.ceiling[2]);
	data->line->floor_color = get_color(1, data->map.floor[0],
			data->map.floor[1], data->map.floor[2]);
	data->line->perp_wall_dist = calculate_perp_wall_dist(data);
	data->line->line_height = (M_H / data->line->perp_wall_dist);
	data->line->draw_start = -data->line->line_height / 2 + M_H / 2;
	if (data->line->draw_start < 0)
		data->line->draw_start = 0;
	data->line->draw_end = data->line->line_height / 2 + M_H / 2;
	if (data->line->draw_end >= M_H)
		data->line->draw_end = M_H - 1;
	init_tex_line(data);
}

void	draw_texture_color(t_data *data, int x, int i)
{
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;

	step = 1.0 * TEX_HEIGHT / data->line->line_height;
	tex_pos = (data->line->draw_start - M_H / 2 + data->line->line_height / 2) * step;
	while (i < data->line->draw_end)
	{
		tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		//color = data->line->texture[data->ray->side - 1][TEX_HEIGHT * tex_y + data->line->tex_x];
		color = ft_get_pixel_img(data->line->texture[data->ray->side - 1], data->line->tex_x, tex_y);
		my_mlx_pixel_put(data->img, x, i, color);
		i++;
	}
}

void	pixel_line(t_data *data, int x)
{
	// int	i;

	// i = 0;
	// while (i < data->line->draw_start)
	// {
	// 	my_mlx_pixel_put(data->img, x, i, data->line->ceiling_color);
	// 	i++;
	// }
	draw_texture_color(data, x, data->line->draw_start);
	// i = data->line->draw_end;
	// while (i < M_H - 1)
	// {
	// 	my_mlx_pixel_put(data->img, x, i, data->line->floor_color);
	// 	i++;
	// }
}

void	draw_line(t_data *data, int x)
{
	init_line(data);
	pixel_line(data, x);
}
