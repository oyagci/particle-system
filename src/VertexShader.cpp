#include "VertexShader.h"
#include <iostream>

VertexShader::VertexShader()
{
}

VertexShader::~VertexShader()
{
	glDeleteShader(_id);
}

bool VertexShader::Compile()
{
	GLuint shader = 0;
	const GLchar *srcp = nullptr;
	int success = 0;

	if (!isLoaded()) return false;

	shader = glCreateShader(GL_VERTEX_SHADER);

	srcp = getSrc().c_str();

	glShaderSource(shader, 1, &srcp, nullptr);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (success > 0) {
		_id = shader;
		_compiled = true;
	}
	else {
		char buf[512];
		glGetShaderInfoLog(shader, sizeof(buf), nullptr, buf);

		std::cerr << buf << std::endl;
	}

	return static_cast<bool>(success);
}
