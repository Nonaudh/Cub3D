/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:31:15 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/25 09:01:52 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "libft.h"
# include "point.h"
# include "math.h"
# include <X11/keysym.h>

# define PI M_PI
# define KEY_NB 16

typedef struct s_data	t_data;
typedef struct s_map	t_map;
typedef struct s_sprite	t_sprite;

typedef enum e_direction
{
	NONE,
	NORTH,
	SOUTH,
	EAST,
	WEST,
}	t_dir;

typedef enum e_keyboard
{
	KEY_W,
	KEY_A,
	KEY_S,
	KEY_D,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_MAP,
	KEY_UP_MAP,
	KEY_DOWN_MAP,
	KEY_F,
	KEY_P,
	KEY_MOUSE,
	KEY_FOG,
	KEY_DOOR,
	KEY_SPRITE,
	KEY_FLOOR_C,
}	t_keyboard;

typedef struct s_player
{
	t_dir		dir;
	t_point		pos;
	double		position[2];
	double		dir_angle;
	double		v_dir[2];
	double		v_plane[2];
	int			keyboard[KEY_NB];
	double		offset_y;
	t_sprite	*player_s;
	bool		active;
}	t_player;

t_dir	get_direction(char c);
int		inside_a_wall(t_data *data, double x, double y, t_map *m);
void	move_player(t_data *data, int keysym, double speed);
void	rotate_player(t_data *data, double speed);
int		handle_input(t_data *data);
void	handle_action(t_data *data);
bool	init_player_sprite(t_data *data);
void	update_anim_player(void *ptr);
void	update_pos(t_data *data, double *pos[2]);

#endif
