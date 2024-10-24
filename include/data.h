/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:28:17 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/23 17:17:09 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "map.h"
# include "minimap.h"
# include "graph.h"
# include "mlx.h"
# include "player.h"
# include "parse.h"
# include "ray.h"
# include "draw_line.h"
# include "sprite.h"
# include <sys/time.h>
# include <stdint.h>

# define M_W 800

typedef struct s_minimap	t_minimap;
typedef struct s_img		t_img;
typedef struct s_win		t_win;
typedef struct s_ray		t_ray;
typedef struct s_line		t_line;
typedef struct s_sprite		t_sprite;
typedef struct s_floor_celling		t_floor_celling;

typedef struct s_data
{
	t_win		*win;
	t_img		*img;
	t_map		map;
	t_minimap	*mnmap;
	t_player	player;
	t_ray		*ray;
	t_line		*line;
	double		zdist[M_W];
	t_sprite	**arr_s;
	uint64_t	start_time;
	uint64_t	last_update;
	int			fps;
	t_floor_celling	*floor_c;
}	t_data;

int			init_data(t_data *data, char **argv);
void		free_data(t_data *data);
uint64_t	get_time(void);
uint64_t	time_past(t_data *data);
bool		update(t_data *data);
bool		init_textures(t_data *data);

#endif
