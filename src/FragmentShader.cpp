#include "common.h"
#include "FragmentShader.h"
#include <string>

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

	if (success) {
		_id = shader;
		_compiled = true;
	}

	return static_cast<bool>(success);
}
