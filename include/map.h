/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:40:37 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/26 13:47:24 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include "libft.h"
# include "player.h"

# define M_W 800 /*1920*/

typedef enum e_door_status
{
	CLOSE,
	CLOSING,
	OPEN,
	OPENING,
}	t_dstatus;

typedef enum e_door_derection
{
	NODIR,
	NS,
	EW,
}	t_d_dir;

typedef struct s_door
{
	t_d_dir		dir;
	t_dstatus	status;
	int			pos_x;
	int			pos_y;
	int			curr_frame;
	int			nb_frames;
	int			delay;
	int			_tmp_delay;
	double		zdist[M_W];
	double		curr_dist;
}	t_door;

typedef struct s_map
{
	char		**map;
	size_t		height;
	size_t		width;
	int			floor[3];
	int			ceiling[3];
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	size_t		curr_sprite;
	size_t		sprite_nb;
	char		**sprites;
	t_player	player;
	size_t		nb_doors;
	t_door		*doors;
}	t_map;

void	init_map(t_map *map);
void	free_map(t_map *map);

#endif
