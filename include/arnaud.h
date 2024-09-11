#ifndef ARNAUD_H
# define ARNAUD_H

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
}	t_player;

typedef struct s_cub
{
	void		*mlx;
	void		*mlx_windows;
	t_img		img;
	t_player	player;
}	t_cub;

void	create_image(void *mlx, void *mlx_windows);

#endif