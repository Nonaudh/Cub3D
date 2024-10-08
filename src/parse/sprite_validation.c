/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:45:36 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/07 08:40:03 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	is_valid_xpm(char *file)
{
	size_t	len;

	len = 0;
	if (!file)
		return (false);
	len = ft_strlen(file);
	if (len < 5 || ft_strncmp(&file[len - 4], ".xpm", -1))
		return (err_sprite(0, file));
	return (true);
}