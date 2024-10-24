/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:05:21 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/24 16:48:06 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_line.h"

static void	init_tex_line(t_data *data, int image)
{
	double	wall_x;
	int		tex_width;

	if (image)
		tex_width = data->line->texture[image].width;
	else
		tex_width = data->line->texture[data->ray->side - 1].width;
	data->line->tex_num = data->ray->side;
	if (data->ray->side == EAST || data->ray->side == WEST)
		wall_x = data->player.position[1]
			+ data->line->perp_wall_dist * data->ray->ray_dir[1];
	else
		wall_x = data->player.position[0]
			+ data->line->perp_wall_dist * data->ray->ray_dir[0];
	wall_x -= floor(wall_x);
	data->line->tex_x = (int)(wall_x * (double)(tex_width));
	if ((data->ray->side == EAST || data->ray->side == WEST)
		&& data->ray->ray_dir[0] > 0)
		data->line->tex_x = tex_width - data->line->tex_x - 1;
	if ((data->ray->side == SOUTH || data->ray->side == NORTH)
		&& data->ray->ray_dir[1] < 0)
		data->line->tex_x = tex_width - data->line->tex_x - 1;
}

static void	init_line(t_data *data, int image)
{
	data->line->ceiling_color = get_color(1, data->map.ceiling[0],
			data->map.ceiling[1], data->map.ceiling[2]);
	data->line->floor_color = get_color(1, data->map.floor[0],
			data->map.floor[1], data->map.floor[2]);
	data->line->perp_wall_dist = calculate_perp_wall_dist(data);
	data->line->line_height = (M_H / data->line->perp_wall_dist);
	data->line->draw_start = (-data->line->line_height / 2 + M_H / 2)
		+ data->player.offset_y;
	if (data->line->draw_start < 0)
		data->line->draw_start = 0;
	data->line->draw_end = (data->line->line_height / 2 + M_H / 2)
		+ data->player.offset_y;
	if (data->line->draw_end >= M_H)
		data->line->draw_end = M_H - 1;
	init_tex_line(data, image);
}

static void	draw_texture_color(t_data *data, int x, int i, int image)
{
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;
	t_img	texture;

	if (image)
		texture = data->line->texture[image];
	else
		texture = data->line->texture[data->ray->side - 1];
	step = 1.0 * texture.height / data->line->line_height;
	tex_pos = (data->line->draw_start - data->player.offset_y - M_H / 2
			+ data->line->line_height / 2) * step;
	while (i < data->line->draw_end)
	{
		tex_y = (int)tex_pos & (texture.height - 1);
		tex_pos += step;
		color = ft_get_pixel_img(texture, data->line->tex_x, tex_y);
		if (image && color != (int)0xFF000000)
			my_mlx_pixel_put(data->img, x, i, color);
		if (!image)
			my_mlx_pixel_put(data->img, x, i, color);
		i++;
	}
}

static void	pixel_line(t_data *data, int x, int image)
{
	int	i;

	i = 0;
	while (i < data->line->draw_start)
		i++;
	draw_texture_color(data, x, i, image);
	i = data->line->draw_end;
	while (i < M_H - 1)
		i++;
}

void	draw_line(t_data *data, int x)
{
	init_line(data, 0);
	data->zdist[x] = data->line->perp_wall_dist;
	pixel_line(data, x, 0);
	if (data->map.map[data->ray->map[1]][data->ray->map[0]] == 'D')
	{
		init_line(data, 6);
		pixel_line(data, x, 6);
	}
}
