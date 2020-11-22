#pragma once
#include "GLEW/glew.h"
#define NULL 0
#ifdef __cplusplus
extern "C" {
#endif 
#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCheck())
static void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

static int GLLogCheck()
{
	GLenum Error;
	
	while (Error = glGetError())
	{
		printf("[OPENGL ERROR] (%d)\n", Error);
	}
	return 1;
}
#ifdef __cplusplus
}
#endif