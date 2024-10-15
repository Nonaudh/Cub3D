/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:52:10 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/30 16:12:37 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "draw_line.h"
#include "graph.h"

void	init_ray(t_data *data, int x)
{
	data->ray->camera_x = (2 * (x / (double)M_W)) - 1;
	data->ray->ray_dir[0] = data->player.v_dir[0]
		+ (data->player.v_plane[0] * data->ray->camera_x);
	data->ray->ray_dir[1] = data->player.v_dir[1]
		+ (data->player.v_plane[1] * data->ray->camera_x);
	data->ray->map[0] = (int)data->player.position[0];
	data->ray->map[1] = (int)data->player.position[1];
	data->ray->delta_dist_x = fabs(1 / data->ray->ray_dir[0]);
	data->ray->delta_dist_y = fabs(1 / data->ray->ray_dir[1]);
}

void	calculating_initial_side_dist(t_data *data)
{
	if (data->ray->ray_dir[0] < 0)
	{
		data->ray->step_x = -1;
		data->ray->side_dist_x = (data->player.position[0] - data->ray->map[0])
			* data->ray->delta_dist_x;
	}
	else
	{
		data->ray->step_x = 1;
		data->ray->side_dist_x = (data->ray->map[0] + 1.0
				- data->player.position[0]) * data->ray->delta_dist_x;
	}
	if (data->ray->ray_dir[1] < 0)
	{
		data->ray->step_y = -1;
		data->ray->side_dist_y = (data->player.position[1]
				- data->ray->map[1]) * data->ray->delta_dist_y;
	}
	else
	{
		data->ray->step_y = 1;
		data->ray->side_dist_y = (data->ray->map[1] + 1.0
				- data->player.position[1]) * data->ray->delta_dist_y;
	}
}

t_dir	define_side(t_data *data)
{
	if (data->ray->side_dist_x < data->ray->side_dist_y)
	{
		if (data->ray->ray_dir[0] < 0)
			return (WEST);
		else
			return (EAST);
	}
	else
	{
		if (data->ray->ray_dir[1] < 0)
			return (NORTH);
		else
			return (SOUTH);
	}
	return (NONE);
}
#include <stdio.h>

void	calculating_ray_size(t_data *data)
{
	while (1)
	{
		if (data->ray->side_dist_x < data->ray->side_dist_y)
		{
			data->ray->side = define_side(data);
			data->ray->side_dist_x += data->ray->delta_dist_x;
			data->ray->map[0] += data->ray->step_x;
		}
		else
		{
			data->ray->side = define_side(data);
			data->ray->side_dist_y += data->ray->delta_dist_y;
			data->ray->map[1] += data->ray->step_y;
		}
		if (data->map.map[data->ray->map[1]][data->ray->map[0]] == '1')
			break ;
	}
	// if (data->ray->ray_dir[0] == data->player.v_dir[0] && data->ray->ray_dir[1] == data->player.v_dir[1])
	// 	printf("side; %d  dir_x; %f  dir_y; %f\n", data->ray->side, data->ray->ray_dir[0], data->ray->ray_dir[1]);
}

int	raycasting(t_data *data)
{
	int	x;

	x = 0;
	while (x < M_W)
	{
		init_ray(data, x);
		calculating_initial_side_dist(data);
		calculating_ray_size(data);
		draw_line(data, x);
		draw_floor_celling(data, x);
		x++;
	}
	return (0);
}
