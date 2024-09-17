#include "cube.h"

void	set_screen_to_grey(t_img* img)
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

	i = -5;
	while (i < 5)
	{
		j = -5;
		while (j < 5)
		{
			my_mlx_pixel_put(img, x + j, y + i, 0x00FFFF00);
			j++;
		}
		i++;
	}
}

void	draw_vector_dir_tmp(t_img *img, t_player *p)
{
	int	i;
	int	j;

	i = -2;
	while (i < 2)
	{
		j = -2;
		while (j < 2)
		{
			//my_mlx_pixel_put(img, x + j, y + i, 0x00FF00FF);
			j++;
		}
		i++;
	}
}
void	draw_vector_dir(t_img *img, t_player *p)
{
	float	i;

	i = 0;
	while (i < 1)
	{
		my_mlx_pixel_put(img, p->p_x + (i * (cos(p->dir_angle) * 100)), p->p_y + (i * (sin(p->dir_angle) * 100)), 0x00FF00FF);
		i += 0.01;
	}
}

void	make_a_white_square(t_img *img, t_map *map, int x, int i)
{
	int	y;
	int	z;

	y = 1;
	while (y < map->square_lenght - 1)
	{
		z = 1;
		while (z < map->square_lenght - 1)
		{
			my_mlx_pixel_put(img, (i * map->square_lenght) + z, (x * map->square_lenght) + y, 0x00000000);
			z++;
		}
		y++;
	}
}
void	make_a_black_square(t_img *img, t_map *map, int x, int i)
{
	int	y;
	int	z;

	y = 1;
	while (y < map->square_lenght - 1)
	{
		z = 1;
		while (z < map->square_lenght - 1)
		{
			my_mlx_pixel_put(img, (i * map->square_lenght) + z, (x * map->square_lenght) + y, 0x00FFFFFF);
			z++;
		}
		y++;
	}
}

void	color_square(t_img *img, t_map *map, int x, int i)
{
	if (map->map[x][i] == 1)
		make_a_white_square(img, map, x, i);
	if (map->map[x][i] == 0)
		make_a_black_square(img, map, x, i);
}

void	draw_map(t_img *img, t_map *map)
{
	int	i;
	int	x;

	x = 0;
	while (x < map->map_height)
	{
		i = 0;
		while (i < map->map_width)
		{
			color_square(img, map, x, i);
			i++;
		}
		x++;
	}
}
