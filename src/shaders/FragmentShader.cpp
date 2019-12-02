#include "FragmentShader.h"
#include <iostream>

FragmentShader::FragmentShader()
{
}

FragmentShader::~FragmentShader()
{
	glDeleteShader(_id);
}

bool FragmentShader::Compile()
{
	GLuint shader = 0;
	const GLchar *srcp = nullptr;
	int success = 0;

	if (!isLoaded()) return false;

	shader = glCreateShader(GL_FRAGMENT_SHADER);

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

		std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED " << buf << std::endl;
	}

	return static_cast<bool>(success);
}
