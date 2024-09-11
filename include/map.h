/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:40:37 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/11 16:07:08 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>

typedef struct	s_map
{
	int	height;
	int	width;
	int	floor[3];
	int	ceiling[3];
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
} t_map;

void	init_map(t_map *map);
void	free_map(t_map *map);
#endif
