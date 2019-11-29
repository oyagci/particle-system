#include "ShaderProgram.h"

bool ShaderProgram::Compile()
{
	GLuint program = 0;

	if (!_vs || !_fs) return false;

	program = glCreateProgram();
	glAttachShader(_vs->getId(), GL_VERTEX_SHADER);
	glAttachShader(_fs->getId(), GL_FRAGMENT_SHADER);
	glLinkProgram(program);

	return true;
}
