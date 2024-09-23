#include "cube.h"

void	rotate_player(t_player *p, double size)
{
	double tmp;

	p->dir_angle += size;
	tmp = p->v_dir[0];
	p->v_dir[0] = cos(size) * tmp - sin(size) * p->v_dir[1];
	p->v_dir[1] = sin(size) * tmp + cos(size) * p->v_dir[1];

	tmp = p->v_plane[0];
	p->v_plane[0] = cos(size) * tmp - sin(size) * p->v_plane[1];
	p->v_plane[1] = sin(size) * tmp + cos(size) * p->v_plane[1];

	// printf("dir_x; %f  dir_y; %f\n", p->v_dir[0], p->v_dir[1]);
	// printf("plan_x; %f  plan_y; %f\n", p->v_plane[0], p->v_plane[1]);
}