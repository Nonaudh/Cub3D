/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:34:19 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/26 12:44:54 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <fcntl.h>
# include "error.h"
# include "def_color.h"
# include "libft.h"
# include "map.h"
# include "data.h"

typedef struct s_data	t_data;

typedef struct s_init_sprite
{
	bool	animated;
	double	x;
	double	y;
	int		w_frame;
	int		h_frame;
	int		x_div;
	int		y_div;
	int		offset;
	int		nb_frame;
	int		delay;
}	t_s_init;

char	*ft_readfile(char *file);
bool	initialize_map(t_map *map, char *path);
bool	get_infos(t_map *map, char **arr, size_t i);
bool	get_map_colors(t_map *map, char *str);
bool	handle_map_err(t_map *map);
bool	missing_att(t_map *map);
bool	is_valid_xpm(char *file);
bool	get_sprite(t_map *map, char *str);
bool	init_arr_sprites(t_data *data);
void	is_valid_character(t_map *map, int pos[2], size_t *unknow);
bool	init_doors(t_map *map);
bool	is_num(char *str);
bool	is_valid_arg(char *str);
bool	valid_spn(t_map *map, char *str);

#endif
