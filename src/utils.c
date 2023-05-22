#include "utils.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <math.h>

double degree_to_radian(double degree)
{
	return degree * M_PI / 180.0;
}

void init_vec3(vec3 *vector, float x, float y, float z)
{
	vector->x = x;
	vector->y = y;
	vector->z = z;
}
