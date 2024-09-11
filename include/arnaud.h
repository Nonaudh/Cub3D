#ifndef ARNAUD_H
# define ARNAUD_H

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

#include <X11/X.h>
#include <X11/keysym.h>

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

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_window;
}	t_mlx;

typedef struct s_cub
{
	t_mlx		mlx;
	t_img		img;
	t_player	player;
}	t_cub;

//void	create_image(void *mlx, void *mlx_windows);

#endif