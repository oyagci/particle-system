#pragma once

#include "VertexShader.h"
#include "FragmentShader.h"
#include <memory>

class AShaderProgram
{
public:
	virtual ~AShaderProgram() { };

	virtual bool Compile() = 0;
	virtual void SetVertex(std::unique_ptr<VertexShader> vs)
	{
		_vs = std::move(vs);
	}
	virtual void SetFragment(std::unique_ptr<FragmentShader> fs)
	{
		_fs = std::move(fs);
	}

protected:
	GLuint _id;
	std::unique_ptr<VertexShader> _vs;
	std::unique_ptr<FragmentShader> _fs;
};
