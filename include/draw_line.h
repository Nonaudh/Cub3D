#ifndef DRAW_LINE_H
# define DRAW_LINE_H

typedef struct s_cub t_cub;

typedef struct s_line
{
	double	perp_wall_dist;
	double	line_height;
	double	draw_start;
	double	draw_end;
	int		celling_color;
	int		floor_color;
}	t_line;

void    draw_line(t_cub *c, int x);
void    pixel_line(t_cub *c, int x);
void    init_line(t_cub *c);
double  calculate_perp_wall_dist(t_cub *c);

# endif
