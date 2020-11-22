#include "System.h"

void startsystem(unsigned int width, unsigned int height, bool fullscreen)
{
	startdrawing(width, height, fullscreen); //Create window and pixel buffer
	start(); // execute the code in the start
	startupdating(); // start Updating the engine
}

void startupdating()
{
	float FrameTime = 0.0f;
	while (!glfwWindowShouldClose(window)) // keep updating as long as the windows is open
	{
		clock_t framestart = clock(); // get time before updating the frame
		Update_Keyboard(); // Update Keyboard and Mouse input
		update(FrameTime); // Update main thread
		draw(); // Draw the Pixel buffer
		clock_t frameend = clock(); // get time after updating the frame
		FrameTime = frameend - framestart; // calculate frametime
	}
}
