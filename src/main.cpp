#include "common.h"
#include "engine/Engine.hpp"

#include "shaders/VertexShader.h"
#include "shaders/FragmentShader.h"
#include "shaders/ShaderProgram.h"
#include <memory>

int	main()
{
	Engine e;
	std::unique_ptr<VertexShader> vs;
	std::unique_ptr<FragmentShader> fs;
	std::unique_ptr<ShaderProgram> sp;

	vs = std::make_unique<VertexShader>();
	vs->LoadSource("./shaders/basic.vs.glsl");
	vs->Compile();

	fs = std::make_unique<FragmentShader>();
	fs->LoadSource("./shaders/basic.fs.glsl");
	fs->Compile();

	sp = std::make_unique<ShaderProgram>();
	sp->SetVertex(move(vs));
	sp->SetFragment(move(fs));

	sp->Compile();

	e.Run();
	return 0;
}
