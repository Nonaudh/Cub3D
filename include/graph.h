/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:32:41 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/23 17:17:44 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include "mlx.h"
# include "libft.h"
# include "math.h"
# include "point.h"
# include <X11/keysym.h>
# include "data.h"
# include "sprite.h"

# define M_W 800
# define M_H 600
# define M_NAME "cub3D"
# define M_RED 84
# define M_GREEN 122
# define M_BLUE 165
# define PI M_PI

typedef struct s_data	t_data;
typedef struct s_sprite	t_sprite;

typedef struct s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
}	t_win;

typedef struct s_img
{
	t_win	*win;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

t_win			*ft_initmlx(void);
void			free_win(t_win *win);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
int				get_color(double dist, int r, int g, int b);
t_img			*new_img(t_win *win, int w, int h);
void			free_img(void *ptr);
void			draw_circle(t_img *img, t_point center, int r, int color);
int				handle_keypress(int keysym, t_data *data);
int				alpha(double opacity, int cback, int cfront);
void			copy_img_to_win(t_data *data, t_sprite *sprite, int x, int y);
unsigned int	ft_get_pixel_img(t_img img, int x, int y);
void			put_pixel_win(t_data *data, int x, int y, int color);
int				handle_keyrelease(int keysym, t_data *data);

#endif
