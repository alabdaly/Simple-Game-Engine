#ifndef MATHLIB_H
#define MATHLIB_H
#include <stdlib.h>
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {

#endif 
typedef struct vec2 // 2d float point
{
	float x, y;
} vec2;

vec2 Vec2(float x, float y);

typedef struct ivec2 // 2d int point
{
	int x, y;
} ivec2;

void swap(float *x, float *y);
#ifdef __cplusplus
}
#endif
#endif // ! Math.h
