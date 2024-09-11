/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:20:03 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/11 10:08:07 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void    set_screen_to_grey(t_img* img)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(img, x, y, 0x00808080);
			x++;
		}
		y++;
	}	
}

void	draw_player(t_img *img, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			my_mlx_pixel_put(img, x + j, y + i, 0x00FFFF00);
			j++;
		}
		i++;
	}
}

int	draw_image(t_cub *c)
{
	if (!c->mlx.mlx_window)
		return (0);
	set_screen_to_grey(&c->img);
	draw_player(&c->img, c->player.pos_x, c->player.pos_y);

	mlx_put_image_to_window(c->mlx.mlx, c->mlx.mlx_window, c->img.img, 0, 0);

	return (0);
}

int	handle_keypress(int keysym, t_cub *c)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(c->mlx.mlx, c->img.img);
		mlx_destroy_window(c->mlx.mlx, c->mlx.mlx_window);
		c->mlx.mlx_window = NULL;
	}
	if (keysym == XK_w && c->player.pos_y >= 0 + 5)
		c->player.pos_y -= 5;
	if (keysym == XK_s && c->player.pos_y <= WINDOW_HEIGHT - 5)
		c->player.pos_y += 5;
	if (keysym == XK_a && c->player.pos_x >= 0 + 5)
		c->player.pos_x -= 5;
	if (keysym == XK_d && c->player.pos_x <= WINDOW_WIDTH - 5)
		c->player.pos_x += 5;
	
	return (0);
}

void	looping(t_cub *c)
{
	mlx_loop_hook(c->mlx.mlx, &draw_image, c);
	mlx_hook(c->mlx.mlx_window, KeyPress, KeyPressMask, &handle_keypress, c);
	mlx_loop(c->mlx.mlx);
}

void	default_set_struct(t_cub *c)
{
	c->mlx.mlx = NULL;
	c->mlx.mlx_window = NULL;
	c->img.img = NULL;
	c->player.pos_x = 100;
	c->player.pos_y = 100;
}

void	open_window_mlx(t_cub *c)
{
	default_set_struct(c);

	c->mlx.mlx = mlx_init();
	c->mlx.mlx_window = mlx_new_window(c->mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");

	c->img.img = mlx_new_image(c->mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	c->img.addr = mlx_get_data_addr(c->img.img, &c->img.bpp, &c->img.line_len, &c->img.endian);

	looping(c);

	//mlx_destroy_window(c->mlx.mlx, c->mlx.mlx_window);
	mlx_destroy_display(c->mlx.mlx);
	free(c->mlx.mlx);
}

int	main(void)
{
	t_cub c;

	open_window_mlx(&c);
	return (0);
}
