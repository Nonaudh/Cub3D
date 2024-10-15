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
	// if (inside_a_wall(p->position[0] + p->v_dir[0] * speed,
	// 	p->position[1] + p->v_dir[1] * speed, m))
	// 	return ;
	if (!inside_a_wall(p->position[0] + p->v_dir[0] * speed, p->position[1], m))	
		p->position[0] += p->v_dir[0] * speed;
	if (!inside_a_wall(p->position[0], p->position[1] + p->v_dir[1] * speed, m))
		p->position[1] += p->v_dir[1] * speed;
}

void	move_player_back(t_player *p, t_map *m, double speed)
{
	// if (inside_a_wall(p->position[0] - p->v_dir[0] * speed,
	// 	p->position[1] - p->v_dir[1] * speed, m))
	// 	return ;
	if (!inside_a_wall(p->position[0] - p->v_dir[0] * speed, p->position[1], m))
		p->position[0] -= p->v_dir[0] * speed;
	if (!inside_a_wall(p->position[0], p->position[1] - p->v_dir[1] * speed, m))
		p->position[1] -= p->v_dir[1] * speed;
}

void	move_player_right(t_player *p, t_map *m, double speed)
{
	double	new_angle;

	new_angle = p->dir_angle + PI * 0.5;
	// if (inside_a_wall(p->position[0] + cos(new_angle) * speed,
	// 	p->position[1] + sin(new_angle) * speed, m))
	// 	return ;
	if (!inside_a_wall(p->position[0] + cos(new_angle) * speed, p->position[1], m))
		p->position[0] += cos(new_angle) * speed;
	if (!inside_a_wall(p->position[0], p->position[1] + sin(new_angle) * speed, m))
		p->position[1] += sin(new_angle) * speed;
}

void	move_player_left(t_player *p, t_map *m, double speed)
{
	double	new_angle;

	new_angle = p->dir_angle - PI * 0.5;
	// if (inside_a_wall(p->position[0] + cos(new_angle) * speed,
	// 	p->position[1] + sin(new_angle) * speed, m))
	// 	return ;
	if (!inside_a_wall(p->position[0] + cos(new_angle) * speed, p->position[1], m))
		p->position[0] += cos(new_angle) * speed;
	if (!inside_a_wall(p->position[0], p->position[1] + sin(new_angle) * speed, m))
		p->position[1] += sin(new_angle) * speed;
}

double	define_speed(int keysym)
{
	static double	speed[4];
	static void		*flag = NULL;

	if (!flag)
	{
		ft_bzero(speed, sizeof(double) * 4);
		flag = (void *)1;
	}
	if (keysym == KEY_W)
	{
		if (speed[KEY_W] >= 0.12)
			return (speed[KEY_W]);
		speed[KEY_W] += 0.01;
		printf("speed; %f\n", speed[KEY_W]);
		return (speed[KEY_W]);
	}
	return (0);
}

void	move_player(t_player *p, t_map *m, int keysym, double speed)
{
	// double	new_speed;

	// new_speed = define_speed(keysym);
	if (keysym == KEY_W)
		move_player_forward(p, m, speed);
	if (keysym == KEY_S)
		move_player_back(p, m, speed);
	if (keysym == KEY_D)
		move_player_right(p, m, speed);
	if (keysym == KEY_A)
		move_player_left(p, m, speed);
}
