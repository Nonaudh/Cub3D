/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:58:34 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/17 07:31:38 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->player.keyboard[KEY_W] = 0;
	if (keysym == XK_a)
		data->player.keyboard[KEY_A] = 0;
	if (keysym == XK_s)
		data->player.keyboard[KEY_S] = 0;
	if (keysym == XK_d)
		data->player.keyboard[KEY_D] = 0;
	if (keysym == XK_Right)
		data->player.keyboard[KEY_RIGHT] = 0;
	if (keysym == XK_Left)
		data->player.keyboard[KEY_LEFT] = 0;
	return (0);
}

static void	handle_key_map(int keysym, t_data *data)
{
	if (keysym == XK_m)
		data->player.keyboard[KEY_MAP] = 1;
	if (keysym == XK_equal)
		data->player.keyboard[KEY_UP_MAP] = 1;
	if (keysym == XK_minus)
		data->player.keyboard[KEY_DOWN_MAP] = 1;
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		free_data(data);
		exit(0);
	}
	if (keysym == XK_w)
		data->player.keyboard[KEY_W] = 1;
	if (keysym == XK_a)
		data->player.keyboard[KEY_A] = 1;
	if (keysym == XK_s)
		data->player.keyboard[KEY_S] = 1;
	if (keysym == XK_d)
		data->player.keyboard[KEY_D] = 1;
	if (keysym == XK_Right)
		data->player.keyboard[KEY_RIGHT] = 1;
	if (keysym == XK_Left)
		data->player.keyboard[KEY_LEFT] = 1;
	handle_key_map(keysym, data);
	return (0);
}
