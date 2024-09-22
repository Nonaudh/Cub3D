#include "cube.h"

void	rotate_angle(double *angle, double size)
{
	(*angle) += size;
	if (*angle > 2 * PI)
		*angle = 0;
	if (*angle < 0)
		*angle = 2 * PI;
}