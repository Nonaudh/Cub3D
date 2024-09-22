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

void	draw_vector_pov(t_cub *c)
{
	draw_vector(&c->img, c->player.position, c->player.v_plane, 100);
}

int	draw_image(t_cub *c)
{
	if (!c->mlx.mlx_window)
		return (0);
	set_screen_to_grey(&c->img);

	draw_map(&c->img, &c->map);

	draw_player(&c->img, c->player.position);

	raycasting(c);

	//draw_vector(&c->img, c->player.position, c->player.v_dir, 100);

	//draw_vector_pov(c);

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
	if (keysym == XK_w && c->player.position[0] > 0 + 5)
		move_player(&c->player, keysym, 5);

	if (keysym == XK_s && c->player.position[0] <= WINDOW_HEIGHT - 5)
		move_player(&c->player, keysym, 5);

	if (keysym == XK_a && c->player.position[1] >= 0 + 5)	
		move_player(&c->player, keysym, 5);

	if (keysym == XK_d && c->player.position[1] <= WINDOW_WIDTH - 5)
		move_player(&c->player, keysym, 5);

	if (keysym == XK_Right)
		rotate_angle(&c->player.dir_angle, 0.025 * PI);
	if (keysym == XK_Left)
		rotate_angle(&c->player.dir_angle, - 0.025 * PI);
	c->player.v_dir[0] = cos(c->player.dir_angle);
	c->player.v_dir[1] = sin(c->player.dir_angle);

	c->player.v_plane[0] = cos(c->player.dir_angle + PI * 0.2);
	c->player.v_plane[1] = sin(c->player.dir_angle + PI * 0.2);
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
	int	new_angle;

	c->mlx.mlx = NULL;
	c->mlx.mlx_window = NULL;
	c->img.img = NULL;
	c->player.position[0] = 100;
	c->player.position[1] = 100;
	c->player.dir_angle = 2 * PI;
	c->player.v_dir[0] = cos(c->player.dir_angle);
	c->player.v_dir[1] = sin(c->player.dir_angle);
	printf("dir_x; %f\n", c->player.v_dir[0]);
	printf("dir_y; %f\n", c->player.v_dir[1]);
	c->player.fov = 30;
	c->player.v_plane[0] = 0;
	c->player.v_plane[1] = 0.66;
}

int	copy_map_into_struct(int map[10][10], t_map *m)
{
	int	i;
	int	x;

	x = 0;
	m->map = malloc(sizeof(int *) * m->map_height);
	while (x < m->map_height)
	{
		i = 0;
		m->map[x] = malloc(sizeof(int) * m->map_width);
		while (i < m->map_width)
		{
			m->map[x][i]= map[x][i];
			i++;
		}
		x++;
	}
	return (0);
}

void	print_map_struct(t_map *m) ///////
{
	int	i = 0;
	int	j;

	while (i < m->map_height)
	{
		j = 0;
		while (j < m->map_width)
		{
			ft_printf("%d ", m->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int	define_square_lenght(t_map *map)
{
	int	widht_lenght;
	int	height_lenght;

	widht_lenght = WINDOW_WIDTH / map->map_width;
	height_lenght = WINDOW_HEIGHT / map->map_height;

	if (widht_lenght < height_lenght)
		return (widht_lenght);
	return (height_lenght);
}

int	set_struct_map(t_cub *c)
{
	int map[10][10] ={	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
						{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
						{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
						{1, 0, 1, 0, 0, 1, 1, 1, 0, 1},
						{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
						{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
						{1, 0, 0, 1, 0, 0, 1, 1, 0, 1},
						{1, 0, 0, 1, 1, 0, 1, 1, 0, 1},
						{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
						{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
	c->map.map_width = 10;
	c->map.map_height = 10;
	c->map.square_lenght = define_square_lenght(&c->map);
	copy_map_into_struct(map, &c->map);

	// print_map_struct(&c->map);

	return (0);
}

void	free_the_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->map_height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	open_window_mlx(t_cub *c)
{
	default_set_struct(c);

	set_struct_map(c);

	c->mlx.mlx = mlx_init();
	c->mlx.mlx_window = mlx_new_window(c->mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");

	c->img.img = mlx_new_image(c->mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	c->img.addr = mlx_get_data_addr(c->img.img, &c->img.bpp, &c->img.line_len, &c->img.endian);

	looping(c);

	free_the_map(&c->map);
	mlx_destroy_display(c->mlx.mlx);
	free(c->mlx.mlx);
}

int	main(void)
{
	t_cub c;

	open_window_mlx(&c);
	return (0);
}
