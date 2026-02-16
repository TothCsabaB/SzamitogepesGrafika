#ifndef CUBOID_H
#define CUBOID_H

typedef struct
{
	double x;
	double y;
	double z;
} Cuboid;

void set_size(Cuboid* cube, double x, double y, double z);

double calc_volume(Cuboid* cube);

double calc_surface(Cuboid* cube);

int is_square_face(Cuboid* cube);

#endif