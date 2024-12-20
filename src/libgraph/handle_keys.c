/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:58:34 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/12 10:19:28 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int	handle_keyrelease(int keysym, t_data *data)
{
	handle_keyrelease_anim(keysym, data);
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
	if (keysym == XK_f)
		data->player.keyboard[KEY_F] = 0;
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

static void	key_press_bonus(int keysym, t_data *data)
{
	if (keysym == XK_f)
		data->player.keyboard[KEY_F] = 1;
	if (keysym == XK_p)
		data->player.keyboard[KEY_P] = 1;
	if (keysym == XK_o)
		data->player.keyboard[KEY_MOUSE] = 1;
	if (keysym == XK_i)
		data->player.keyboard[KEY_FOG] = 1;
	if (keysym == XK_u)
		data->player.keyboard[KEY_DOOR] = 1;
	if (keysym == XK_y)
		data->player.keyboard[KEY_SPRITE] = 1;
	if (keysym == XK_t)
		data->player.keyboard[KEY_FLOOR_C] = 1;
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
	key_press_bonus(keysym, data);
	handle_key_map(keysym, data);
	return (0);
}

void	handle_action(t_data *data)
{
	t_door	*door;
	int		x;
	int		y;

	x = (int)data->player.position[0] + (int)round(data->player.v_dir[0]);
	y = (int)data->player.position[1] + (int)round(data->player.v_dir[1]);
	door = get_door(data, x, y);
	if (door)
	{
		if (door->status == OPEN)
			door->status = CLOSING;
		if (door->status == CLOSE)
			door->status = OPENING;
	}
}
