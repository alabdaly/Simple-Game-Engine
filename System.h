#pragma once
#include <time.h>
#include "Renderer.h"
#include "Input.h"
#include "Mathlib.h"

#ifdef __cplusplus
extern "C" {
#endif 
void start();

void update(float dt);
void startsystem(unsigned int width, unsigned int height, bool fullscreen);
void startupdating();

#ifdef __cplusplus
}
#endif