/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_init_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:01:08 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/25 14:43:12 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	init_data_var(t_data *data)
{
	data->win = NULL;
	data->img = NULL;
	data->mnmap = NULL;
	data->ray = NULL;
	data->line = NULL;
	data->arr_s = NULL;
	data->door_s = NULL;
	data->start_time = 0;
	data->last_update = 0;
	data->fps = 60;
}