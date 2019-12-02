#pragma once

#include "common.h"
#include "IRenderable.h"
#include "shaders/AShaderProgram.h"
#include <memory>

class Particle : public IRenderable
{
public:
	Particle();
	~Particle() override;
	void OnRender() override;

private:
	GLuint _vao;
	GLuint _vbo;
	std::unique_ptr<AShaderProgram> _shader;
};
