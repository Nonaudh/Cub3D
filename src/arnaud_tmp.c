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
	while (y < 600)
	{
		x = 0;
		while (x < 800)
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

int	handle_keypress(int keycode, t_cub *c)
{
	if (keycode == 65362)
	{
		//c->player->pos_x += 10;
	}
	return (0);
}

int	draw_image(t_cub *c)
{
	set_screen_to_grey(c->img);
	draw_player(c->img, c->player->pos_x, c->player->pos_y);
	mlx_hook(c->mlx_windows, 2, 1L<<0, handle_keypress, c); ////
	return (0);
}

void	loop_windows(t_cub *c)
{
	mlx_loop_hook(c->mlx, draw_image, c);
}

void	create_image(void *mlx, void *mlx_windows)
{
	t_cub	c;

	c.mlx = mlx;
	c.mlx_windows = mlx_windows;
	c.img.img = mlx_new_image(c.mlx, 800, 600);
	c.img.addr = mlx_get_data_addr(c.img.img, c.img.bpp, c.img.line_len, c.img.endian);
	loop_windows(&c);
}