/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:30:10 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/16 14:04:35 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool	is_valid_arr(char **arr)
{
	size_t	i;
	char	**tmp;

	i = 0;
	if (ft_arrlen((void **)arr) < 2)
		return (err_sprite(5, NULL));
	while (arr[i])
	{
		ft_strstrim(arr[i]);
		if (i == 0)
			if (!is_valid_xpm(arr[i]))
				return (err_sprite(0, arr[i]));
		tmp = ft_split(arr[i], ' ');
		if (!tmp)
			return (err_sprite(3, NULL));
		if (i != 0 && ft_arrlen((void **)tmp) < 7)
		{
			ft_free_array((void **)tmp);
			return (err_sprite(6, NULL));
		}
		ft_free_array((void **)tmp);
		i++;
	}
	return (true);
}

static bool	init_sprite_info(t_s_init *conf, char **pos)
{
	if (conf->animated && ft_arrlen((void **)pos) != 9)
		return (err_sprite(6, NULL));
	conf->w_frame = ft_atoi(pos[2]);
	conf->h_frame = ft_atoi(pos[3]);
	conf->x_div = ft_atoi(pos[4]);
	conf->y_div = ft_atoi(pos[5]);
	conf->offset = ft_atoi(pos[6]);
	if (conf->animated)
	{
		conf->nb_frame = ft_atoi(pos[7]);
		conf->delay = ft_atoi(pos[8]);
	}
	return (true);
}

static bool	create_sprites(t_data *data, char *path, char **pos, size_t *j)
{
	t_s_init	conf;

	conf.animated = false;
	conf.x = ft_strtod(pos[0]);
	conf.y = ft_strtod(pos[1]);
	if (conf.x < 1 || conf.y < 1 || conf.x > data->map.width
		|| conf.y > data->map.height)
		return (err_sprite(7, NULL));
	if (*j == data->map.sprite_nb)
		return (err_sprite(8, NULL));
	if (path[0] == 'A')
	{
		path++;
		conf.animated = true;
	}
	if (!init_sprite_info(&conf, pos))
		return (false);
	data->arr_s[*j] = new_sprite(data, path);
	if (!data->arr_s[*j])
		return (err_sprite(3, NULL));
	init_sprite(data->arr_s[*j], &conf);
	(*j)++;
	return (true);
}

static bool	data_add_sprite(t_data *data, char **tmp, size_t *j)
{
	char	*path;
	char	**pos;
	size_t	i;

	path = tmp[0];
	i = 1;
	while (tmp[i])
	{
		pos = ft_split(tmp[i], ' ');
		if (!pos)
		{
			ft_free_array((void **)pos);
			ft_free_array((void **)tmp);
			return (err_sprite(3, NULL));
		}
		if (!create_sprites(data, path, pos, j))
		{
			ft_free_array((void **)pos);
			ft_free_array((void **)tmp);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	init_arr_sprites(t_data *data)
{
	size_t	i;
	size_t	j;
	char	**tmp;

	i = 0;
	j = 0;
	if (!data->map.sprite_nb)
		return (true);
	data->arr_s = (t_sprite **)ft_calloc(data->map.sprite_nb
			+ 1, sizeof(t_sprite *));
	if (!data->arr_s)
		return (err_sprite(3, NULL));
	while (data->map.sprites[i])
	{
		tmp = ft_split(data->map.sprites[i], ',');
		if (!is_valid_arr(tmp))
		{
			ft_free_array((void **)tmp);
			return (false);
		}
		if (!data_add_sprite(data, tmp, &j))
			return (false);
		ft_free_array((void **)tmp);
		i++;
	}
	return (true);
}
