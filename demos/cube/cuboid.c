#include "cuboid.h"

#include <math.h>

void set_size(Cuboid* cube, double x, double y, double z)
{
	if (x > 0.0) {
		cube->x = x;
	} else {
		cube->x = NAN;
	}
	
	if (y > 0.0) {
		cube->y = y;
	} else {
		cube->y = NAN;
	}
	
	if (z > 0.0) {
		cube->z = z;
	} else {
		cube->z = NAN;
	}
}

double calc_volume(Cuboid* cube)
{
	double volume = 0;
	volume = cube->x * cube->y * cube->z;
	return volume;
}

double calc_surface(Cuboid* cube)
{
	double surface = 0;
	surface = 2 * (cube->x * cube->y + cube->x * cube->z + cube->y * cube->z);
	return surface;
}

int is_square_face(Cuboid* cube)
{
	if(cube->x == cube-> y || cube->x == cube->z || cube->y == cube->z)
	{
		return 1;
	}else{
		return 0;
	}
}

