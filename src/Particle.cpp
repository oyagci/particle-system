#include "Particle.h"
#include "common.h"

#include "shaders/VertexShader.h"
#include "shaders/FragmentShader.h"
#include "shaders/ShaderProgram.h"
#include <memory>
#include <cassert>

Particle::Particle()
{
	GLfloat vdata[] = { 0.0f, 0.0f, 0.0f };

	std::unique_ptr<VertexShader> vs;
	std::unique_ptr<FragmentShader> fs;
	std::unique_ptr<ShaderProgram> sp;

	vs = std::make_unique<VertexShader>();
	vs->LoadSource("./shaders/basic.vs.glsl");
	assert(vs->Compile());

	fs = std::make_unique<FragmentShader>();
	fs->LoadSource("./shaders/basic.fs.glsl");
	assert(fs->Compile());

	sp = std::make_unique<ShaderProgram>();
	sp->SetVertex(std::move(vs));
	sp->SetFragment(std::move(fs));
	assert(sp->Compile());

	_shader = std::move(sp);
	_shader->Use();

	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);
	
	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vdata), vdata, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3,
		reinterpret_cast<void*>(0));

	glBindVertexArray(0);
}

Particle::~Particle()
{
	glDeleteBuffers(1, &_vao);
	glDeleteBuffers(1, &_vbo);
}

void Particle::OnRender()
{
	_shader->Use();
	glBindVertexArray(_vao);
	glDrawArrays(GL_POINTS, 0, 3);
}
