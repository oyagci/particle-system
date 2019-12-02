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

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		GLchar buf[1024] = { 0 };
		glGetProgramInfoLog(program, 1024, nullptr, buf);
		std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED: " << buf << std::endl;
	}
	else {
		_id = program;
	}

	return static_cast<bool>(success);
}
