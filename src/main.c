/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:20:03 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/08 10:25:26 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	functionTest(t_data *data) //TODO
{
	t_sprite	*sprite;

	raycasting(data);
	draw_mnmap(data);
	sprite = new_sprite(data, data->map.no);
	copy_img_to_win(data, sprite, M_W / 2 - sprite->width / 2,
			M_H / 2 - sprite->height / 2);
	mlx_put_image_to_window(data->win->mlx_ptr,
		data->win->win_ptr, data->img->img_ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2)
		return (1);
	if (!init_data(&data, argv))
	{
		free_data(&data);
		return (1);
	}
	mlx_loop_hook(data.win->mlx_ptr, &functionTest, &data);
	mlx_hook(data.win->win_ptr,
		KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.win->mlx_ptr);
	free_data(&data);
	return (0);
}
