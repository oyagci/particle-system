#include "common.h"
#include "engine/Engine.hpp"
#include "Particle.h"
#include <memory>

int	main()
{
	Engine e;
	std::unique_ptr<Particle> p;

	p = std::make_unique<Particle>();
	e.AddRenderable(std::move(p));
	e.Run();
	return 0;
}
