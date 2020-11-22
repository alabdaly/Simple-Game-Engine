#include <stdio.h>
#include "System.h"


float TimeSinceStart = 0.0;
float timetoupdate = 1000.0;


typedef struct rect
{
	vec2 pos;
	vec2 size;
} rect;

bool pointvsrect(const vec2 *p, const rect *r)
{
	return (p->x >= r->pos.x && p->y >= r->pos.y
		&&  p->x < r->pos.x + r->size.x && p->y < r->pos.y + r->size.y);
}
vec2 pos;
void start()
{
	pos = Vec2(10, 10);
}
double mx, my;
int mxstart = 0, mystart = 0;

typedef struct enemy
{
	vec2 pos;
	bool alive;
} enemy;


void update(float dt)
{
	Fill(0);
	glfwGetCursorPos(window, &mx, &my);
	vec2 mouse = Vec2(mx, my);
	
	enemy *n = (enemy*)malloc(sizeof(enemy));
	n->alive = true;
	n->pos = Vec2(rand() % Screen_Width, rand() % Screen_Height);
	//free(n);
	int x = 0;
	
    printf("The size of current list is %d\n", x);
	//printf("r");
	x = 0;
	TimeSinceStart += dt;
}





int main()
{
	startsystem(640, 480, 0);
	return 0;
}