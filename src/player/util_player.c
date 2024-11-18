/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:45:04 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/18 13:28:11 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_dir	get_direction(char c)
{
	if (c == 'N')
		return (NORTH);
	if (c == 'S')
		return (SOUTH);
	if (c == 'W')
		return (WEST);
	if (c == 'E')
		return (EAST);
	return (NONE);
}

int	inside_a_wall(t_data *data, int x, int y, t_map *m)
{
	t_door	*door;

	door = get_door(data, x, y);
	if (m->map[y][x] == '1'
		|| (data->visible_door && door && door->dir != NODIR
			&& door->status != OPEN))
		return (1);
	return (0);
}

void	update_anim_player(void *ptr)
{
	t_sprite	*s;
	t_anim		*a;
	t_list		*l;
	int			i;

	i = 0;
	s = (t_sprite *)ptr;
	l = (t_list *)s->anim;
	if (!l)
		return ;
	while (i != s->lst_nb)
	{
		l = l->next;
		i++;
	}
	a = (t_anim *)l->content;
	l = (t_list *)a->frames;
	if (a->_tmp_delay++ == a->delay)
	{
		a->_tmp_delay = 0;
		a->current_frame_num++;
		a->current_frame_num %= ft_lstsize(l);
	}
}

void	update_player_pos(t_data *data)
{
	double	x_dist;
	double	y_dist;

	x_dist = data->player.v_dir[0] * 1.3;
	y_dist = data->player.v_dir[1] * 1.3;
	data->player.player_s->pos_x
		= data->player.position[0] + x_dist;
	data->player.player_s->pos_y
		= data->player.position[1] + y_dist;
}
