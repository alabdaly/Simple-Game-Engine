#include "Draw.h"

color Color(int r, int g, int b) // initialize color
{
	color c;
	c.r = r;
	c.g = g;
	c.b = b;
	return c;
}

void put_pixel(int x, int y, color c) // put pixel in selected x and y position 0, 0 top left of screen
{
	if (y < Screen_Height && y > 0) // if the pixel is inside the screen
	{
		if (x < Screen_Width && x > 0) // if the pixel is inside the screen put it in pixel buffer
		{

			PixelBuffer[(y*(Screen_Width * 3)) + x * 3 + 0] = c.r;
			PixelBuffer[(y*(Screen_Width * 3)) + x * 3 + 1] = c.g;
			PixelBuffer[(y*(Screen_Width * 3)) + x * 3 + 2] = c.b;
		}
	}
}

void put_pixel_size(int x, int y, int fontw, int fonth, color c) // put pixel with width and height
{
	int xx = 0;
	int yy = 0;
	for (; xx < fontw;)
	{
		for (; yy < fonth;)
		{
			put_pixel(x * fontw + xx, y * fonth + yy, c);
			yy += 1;
		}
		yy = 0;
		/*put_pixel(x + 1, y, c);
		put_pixel(x + 2, y, c);
		put_pixel(x + 3, y, c);
		put_pixel(x + 4, y, c);
		put_pixel(x + 5, y, c);
		put_pixel(x + 6, y, c);
		put_pixel(x + 7, y, c);*/
		xx += 1;
	}
}

void Fill(int rgb) // set the whole pixel buffer to rgb value
{
	memset(PixelBuffer, rgb, Screen_Width * Screen_Height * 3);
}

void DrawLine(int x1, int y1, int x2, int y2, color p)
{
	int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
	dx = x2 - x1; dy = y2 - y1;

	

	if (dx == 0) // Line is vertical
	{
		if (y2 < y1) swap(&y1, &y2);
		for (y = y1; y <= y2; y++)  put_pixel(x1, y, p);
		return;
	}

	if (dy == 0) // Line is horizontal
	{
		if (x2 < x1) (&x1, &x2);
		for (x = x1; x <= x2; x++)  put_pixel(x, y1, p);
		return;
	}

	// Line is neither 
	dx1 = abs(dx); dy1 = abs(dy);
	px = 2 * dy1 - dx1;	py = 2 * dx1 - dy1;
	if (dy1 <= dx1)
	{
		if (dx >= 0)
		{
			x = x1; y = y1; xe = x2;
		}
		else
		{
			x = x2; y = y2; xe = x1;

		}

		put_pixel(x, y, p);

		for (i = 0; x < xe; i++)
		{
			x = x + 1;
			if (px < 0)
				px = px + 2 * dy1;
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) y = y + 1; else y = y - 1;
				px = px + 2 * (dy1 - dx1);
			}
			put_pixel(x, y, p);
		}
	}
	else
	{
		if (dy >= 0)
		{
			x = x1; y = y1; ye = y2;
		}
		else
		{
			x = x2; y = y2; ye = y1;
		}

		 put_pixel(x, y, p);

		for (i = 0; y < ye; i++)
		{
			y = y + 1;
			if (py <= 0)
				py = py + 2 * dx1;
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) x = x + 1; else x = x - 1;
				py = py + 2 * (dx1 - dy1);
			}
			 put_pixel(x, y, p);
		}
	}
}

void DrawLineVec2(vec2 xy1, vec2 xy2, color c)
{
	DrawLine(xy1.x, xy1.y, xy2.x, xy2.y, c);
}

void DrawRect(int x, int y, int w, int h, color c) // draw rect borders
{
	
	DrawLine(x, y, x + w, y, c);
	DrawLine(x + w, y, x + w, y + h, c);
	DrawLine(x, y + h, x + w, y + h, c);
	DrawLine(x, y + h, x, y, c);
}

void Fillrect(int x, int y, int w, int h, color c) // draw rect
{
	for (int xx = x; xx < w + x; xx++)
	{
		for (int yy = y; yy < h + y; yy++)
		{
			put_pixel(xx, yy, c);
		}
	}
}