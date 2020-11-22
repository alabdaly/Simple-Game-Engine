#include "Shader.h"

unsigned int MakeShader() // make the shader 
{
	unsigned int s;
	ShaderProgramSource source;
	source = para();


	s = CreateShader(source.VertexSource, source.FragmentSource);
	return s;
}

ShaderProgramSource para()
{
	char* vs;
	char* fs;

	vs = "#version 330 core\n layout(location = 0) in vec2 position;\n layout(location = 1) in vec2 texCoord;\n out vec2 v_TexCoord;\n void main()\n {\n v_TexCoord.x = texCoord.x;\n v_TexCoord.y = 1.0 - texCoord.y;\n gl_Position = vec4(position.x, position.y, 0.0, 1.0);\n };\n";

	fs = "#version 330 core\n layout(location = 0) out vec4 color;\n in vec2 v_TexCoord;\n uniform sampler2D u_Texture;\n void main()\n {\n vec4 texColor = texture(u_Texture, v_TexCoord);\n color = vec4(texColor.rgb, 1.0); };\n";
	ShaderProgramSource Shadersource;
	Shadersource.VertexSource = vs;
	Shadersource.FragmentSource = fs;
	return Shadersource;
} // write the shader

unsigned int CompileShader(unsigned int type, const char* source) // compile the shader
{
	unsigned int id = glCreateShader(type);
	const char* src = source;
	GLCall(glShaderSource(id, 1, &src, NULL));
	GLCall(glCompileShader(id));

	//TODO error handling
	int result;
	GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
	if (!result)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)malloc(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		printf("%s %s %s %s %s", "Error compiling shader", (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment"), "!", message, "\n");
		glDeleteShader(id);
		return 0;
	}

	return id;
}

unsigned int CreateShader(const char* VertexShader, const char* Fragmentshader) // create the shader
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, VertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, Fragmentshader);
	GLCall(glAttachShader(program, vs));
	GLCall(glAttachShader(program, fs));
	GLCall(glLinkProgram(program));
	GLCall(glValidateProgram(program));

	GLCall(glDeleteShader(vs));
	GLCall(glDeleteShader(fs));
	return program;
}

void BindShader(unsigned int shader) // link the shader
{
	GLCall(glUseProgram(shader));
}