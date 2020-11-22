#pragma once
#include "Debuger.h"



typedef struct ShaderProgramSource // opengl Vertex and Fragment shaders
{
	char* VertexSource;
	char* FragmentSource;
} ShaderProgramSource;

ShaderProgramSource para();
unsigned int MakeShader();
unsigned int CompileShader(unsigned int type, const char* source);
unsigned int CreateShader(const char* VertexShader, const char* Fragmentshader);
void BindShader(unsigned int shader);






/*GLint Shader::GetUniformlocation(const std::string& name) const
{
	if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
		return m_UniformLocationCache[name];
	int location = glGetUniformLocation(m_RendererID, name.c_str());
	if (location == -1)
	{
		std::cout << "uniform " << name << " doesn't exist" << std::endl;
	}
	m_UniformLocationCache[name] = location;
	return location;
}*/