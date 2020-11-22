#include "Mathlib.h"


vec2 Vec2(float x, float y) // initialize vec2 variable
{
	vec2 h;
	h.x = x;
	h.y = y;
	return h;
}



void swap(float *x, float *y) // swap two variables
{
	float z = *x;
	*x = *y;
	*y = z;
}

