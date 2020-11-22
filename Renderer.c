#include "Renderer.h"

#ifdef __cplusplus
extern "C" {
#endif 
vertex Vertex(vec2 pos, vec2 tex)
{
	vertex v;
	v.pos = pos;
	v.tex = tex;
	return v;
}

void startdrawing(int w, int h, bool fullscreen)
{
	if (!glfwInit())
		return -1;
	Screen_Width = w; // set screen width
	Screen_Height = h; // set screen height
	PixelBuffer = (char*)malloc(Screen_Width * Screen_Height * 3); // create pixel buffer
	window = glfwCreateWindow(Screen_Width, Screen_Height, "Hello World", fullscreen != 0 ? glfwGetPrimaryMonitor() : NULL, NULL); // create window
	if (!window) // check if window is created
	{
		printf("%s\n", "Window ERROR");
	}

	glfwMakeContextCurrent(window); // set the current window
	if (glewInit() != GLEW_OK) // check if GLEW is ok
		printf("%s\n", "GLEW ERROR");

	vertex screen_quad[6]; // make a quad that fits the screen to write the pixel buffer on
	screen_quad[0] = Vertex(Vec2(-1, -1), Vec2(0.0f, 0.0f));
	screen_quad[1] = Vertex(Vec2(1, -1), Vec2(1.0f, 0.0f));
	screen_quad[2] = Vertex(Vec2(1, 1), Vec2(1.0f, 1.0f));
	screen_quad[3] = Vertex(Vec2(1, 1), Vec2(1.0f, 1.0f));
	//screen_quad[4] = Vertex(Vec2(-1, 1), Vec2(0.0f, 1.0f));
	//screen_quad[5] = Vertex(Vec2(-1, -1), Vec2(0.0f, 0.0f));
	unsigned int indicies[6] = { 0, 1, 2, 2, 3, 0 };
	unsigned int VAO, VBO, IBO;
	GLCall(glCreateVertexArrays(1, &VAO));
	GLCall(glBindVertexArray(VAO));

	GLCall(glGenBuffers(1, &VBO));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, VBO));
	GLCall(glBufferData(GL_ARRAY_BUFFER, 6 * 4 * sizeof(float), screen_quad, GL_STATIC_DRAW));

	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), 0));
	GLCall(glEnableVertexAttribArray(1));
	GLCall(glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid*)offsetof(vertex, tex)));
	unsigned int shader = MakeShader();
	BindShader(shader);
}

void draw()
{
	unsigned int texture; // create a new texture
	GLCall(glGenTextures(1, &texture));
	GLCall(glBindTexture(GL_TEXTURE_2D, texture));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
	GLCall(glActiveTexture(GL_TEXTURE0 + 0));
	GLCall(glBindTexture(GL_TEXTURE_2D, texture));

	GLCall(glClear(GL_COLOR_BUFFER_BIT)); // clear the opengl screen

	GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Screen_Width, Screen_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, PixelBuffer)); // put the PixelBuffer into texture
	GLCall(glBindTexture(GL_TEXTURE_2D, texture));

	GLCall(glDrawArrays(GL_TRIANGLES, 0, 6)); // draw the quad with texture on it
	GLCall(glfwSwapBuffers(window)); // update the screen
	glDeleteTextures(1, &texture); // delete the texture
	/* Poll for and process events */
}

#ifdef __cplusplus
}
#endif