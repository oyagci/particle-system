#include "ShaderProgram.h"
#include <iostream>

bool ShaderProgram::Compile()
{
	int success = 0;
	GLuint program = 0;

	if (!_vs.get() || !_fs.get()) return false;

	program = glCreateProgram();
	glAttachShader(program, _vs->getId());
	glAttachShader(program, _fs->getId());
	glLinkProgram(program);
	glGetShaderiv(program, GL_LINK_STATUS, &success);

	if (success == 0) {
		GLchar buf[512] = { 0 };
		glGetProgramInfoLog(program, 512, NULL, buf);
		std::cout << buf << std::endl;
	}

	_id = program;

	return static_cast<bool>(success);
}
