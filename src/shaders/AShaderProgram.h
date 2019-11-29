#pragma once

#include "VertexShader.h"
#include "FragmentShader.h"

class AShaderProgram
{
public:
	virtual ~AShaderProgram() { };

	virtual bool Compile() = 0;
	virtual void SetVertex(VertexShader *vs) { _vs = vs; }
	virtual void SetFragment(FragmentShader *fs) { _fs = fs; }

protected:
	VertexShader *_vs;
	FragmentShader *_fs;
};
