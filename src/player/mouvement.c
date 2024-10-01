/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:47:45 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/25 12:50:08 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	move_player_forward(t_player *p, t_map *m, double speed)
{
	if (inside_a_wall(p->position[0] + p->v_dir[0] * speed,
		p->position[1] + p->v_dir[1] * speed, m))
		return ;
	p->position[0] += p->v_dir[0] * speed;
	p->position[1] += p->v_dir[1] * speed;
}

void	move_player_back(t_player *p, t_map *m, double speed)
{
	if (inside_a_wall(p->position[0] - p->v_dir[0] * speed,
		p->position[1] - p->v_dir[1] * speed, m))
		return ;	
	p->position[0] -= p->v_dir[0] * speed;
	p->position[1] -= p->v_dir[1] * speed;
}

void	move_player_right(t_player *p, t_map *m, double speed)
{
	double	new_angle;

	new_angle = p->dir_angle + PI * 0.5;
	if (inside_a_wall(p->position[0] + cos(new_angle) * speed,
		p->position[1] + sin(new_angle) * speed, m))
		return ;
	p->position[0] += cos(new_angle) * speed;
	p->position[1] += sin(new_angle) * speed;
}

void	move_player_left(t_player *p, t_map *m, double speed)
{
	double	new_angle;

	new_angle = p->dir_angle - PI * 0.5;
	if (inside_a_wall(p->position[0] + cos(new_angle) * speed,
		p->position[1] + sin(new_angle) * speed, m))
		return ;
	p->position[0] += cos(new_angle) * speed;
	p->position[1] += sin(new_angle) * speed;
}

void	move_player(t_player *p, t_map *m, int keysym, double speed)
{
	if (keysym == XK_w)
		move_player_forward(p, m, speed);
	if (keysym == XK_s)
		move_player_back(p, m, speed);
	if (keysym == XK_d)
		move_player_right(p, m, speed);
	if (keysym == XK_a)
		move_player_left(p, m, speed);
}
