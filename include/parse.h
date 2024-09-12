/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:34:19 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/12 11:49:20 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <fcntl.h>
# include "error.h"
# include "def_color.h"
# include "libft.h"

typedef struct	s_map t_map;

char	*ft_readfile(char *file);
bool	initialize_map(t_map *map, char *path);

#endif
