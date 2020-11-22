#include "Input.h"
#include <Windows.h>
#include "Renderer.h"
bool key_status[255];
bool old_key_status[256];

Key keys[256];


void Update_Keyboard()
{
	
	GLCall(glfwPollEvents());
	glfwGetCursorPos(window, &mousex, &mousey); // update mouse coords
	for (int i = 0; i < 256; i++) // update mouse and keyboard buttons
	{
		
		key_status[i] = GetAsyncKeyState(i);

		keys[i].bPressed = false;
		keys[i].bReleased = false;

		if (key_status[i] != old_key_status[i])
		{
			if (key_status[i] & 0x8000)
			{
				keys[i].bPressed = !keys[i].bHeld;
				keys[i].bHeld = true;
			}
			else
			{
				keys[i].bReleased = true;
				keys[i].bHeld = false;
			}
		}

		old_key_status[i] = key_status[i];
	}
}

Key getkey(int keyID) // get key status
{
	return keys[keyID];
}