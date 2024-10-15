# include "cube.h"

t_img	*init_tex_tab(void)
{
	t_img	*tab;

	tab = malloc(sizeof(t_img) * NB_OF_TEX);
	return (tab);
}

void	set_texture_img(t_data *data, t_img *texture, char *texture_name)
{
	texture->img_ptr = mlx_xpm_file_to_image(data->win->mlx_ptr, texture_name, &texture->width, &texture->height);
	texture->addr = mlx_get_data_addr(texture->img_ptr, &texture->bpp, &texture->l_len, &texture->endian);
}

void	init_textures(t_data *data)
{
	t_line	*line;
	int		i;

	line = data->line;
	line->texture = init_tex_tab();
	i = 0;

	set_texture_img(data, &data->line->texture[NORTH - 1], data->map.no);
	set_texture_img(data, &data->line->texture[SOUTH - 1], data->map.so);
	set_texture_img(data, &data->line->texture[EAST - 1], data->map.ea);
	set_texture_img(data, &data->line->texture[WEST - 1], data->map.we);
	set_texture_img(data, &data->line->texture[4], "textures/wood.xpm");
	set_texture_img(data, &data->line->texture[5], "textures/colorstone.xpm");

	// while (i < NB_OF_TEX)
	// {
	// 	line->texture[i].img_ptr = mlx_xpm_file_to_image(data->win->mlx_ptr, data->map.no, &line->texture[i].width, &line->texture[i].height);
	// 	line->texture[i].addr = mlx_get_data_addr(line->texture[i].img_ptr, &line->texture[i].bpp, &line->texture[i].l_len, &line->texture[i].endian);
	// 	i++;
	// }
}

// void	init_textures_tmp(t_data *data)
// {
// 	t_line	*line;
// 	int		x;
// 	int		y;
// 	int xorcolor;

// 	line = data->line;
// 	line->texture = init_tex_tab();
// 	line->texture[0] = mlx_xpm_file_to_image(data->win->mlx_ptr, data->map.no, &witdh, &height);
// 	x = 0;
// 	while (x < TEX_WIDTH)
// 	{
// 		y = 0;
// 		while (y < TEX_HEIGHT)
// 		{
// 			xorcolor = (x * 256 / TEX_WIDTH) ^ (y * 256 / TEX_HEIGHT);
// 			// line->texture[0][TEX_WIDTH * y + x] = 65536 * 254 * (x != y && x != TEX_WIDTH - y); //flat red texture with black cross
// 			line->texture[1][TEX_WIDTH * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
// 			line->texture[2][TEX_WIDTH * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
// 			line->texture[3][TEX_WIDTH * y + x] = 256 * xorcolor; //xor green
// 			y++;
// 		}
// 		x++;
// 	}
// }
