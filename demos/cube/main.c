#include "cuboid.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
	Cuboid cube;
	double a = 10;
	double b = 12;
	double c = 10;
	printf("A teglatest elei: %0.2lf, %0.2lf, %0.2lf\n", a, b, c);
	double volume, surface, square_face;
	
	set_size(&cube, 10, 12, 10);
	volume = calc_volume(&cube);
	printf("A terfogata: %0.4lf\n", volume);
	
	surface = calc_surface(&cube);
	printf("A felszine: %0.4lf\n", surface);
	
	square_face = is_square_face(&cube);
	if(square_face)
	{
		printf("Van negyzet oldala.\n");
	} else
	{
		printf("Nincs negyzet oldala\n");
	}
	
	printf("%d", square_face);
	return 0;
}