#pragma once
#include "Mathlib.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct Key
{
	bool bPressed;
	bool bReleased;
	bool bHeld;
} Key;

double mousex, mousey;

void Update_Keyboard();

Key getkey(int keyID);
#ifdef __cplusplus
}
#endif