#ifndef DRAW_H
#define DRAW_H


#include "Mathlib.h"
#ifdef __cplusplus
extern "C" {
#endif 

	

unsigned char* PixelBuffer;
int Screen_Width, Screen_Height;
typedef struct color
{
	int r, g, b;
} color;

static const color
White = { 255, 255, 255 }, Red = { 255, 0, 0 }, Yellow = { 255, 255, 0 }, Purple = { 255, 0, 255 }, Green = { 0, 255, 0 }, Cyan = { 0, 255, 255 }, Blue = { 0, 0, 255 };



color Color(int r, int g, int b);

void put_pixel(int x, int y, color c);

void put_pixel_size(int x, int y, int fontw, int fonth, color c);



void Fill(int rgb);

void DrawLineVec2(vec2 xy1, vec2 xy2, color c);

void DrawLine(int x1, int y1, int x2, int y2, color c);

void DrawRect(int x, int y, int w, int h, color c);

void Fillrect(int x, int y, int w, int h, color c);
#ifdef __cplusplus
}
#endif
#endif // !DRAW_H