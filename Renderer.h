#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "Debuger.h"
#include "Math.h"
#include "Draw.h"
#include <stdio.h>
#ifdef __cplusplus
extern "C" {
#endif 
GLFWwindow* window;
typedef struct vertex
{
	vec2 pos;
	vec2 tex;
} vertex;

void startdrawing(int w, int h, bool fullscreen);

void draw();

#ifdef __cplusplus
}
#endif