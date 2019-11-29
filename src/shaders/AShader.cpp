#include "AShader.h"
#include <fstream>
#include <sstream>
#include <iostream>

AShader::AShader() : _loaded(false)
{
}

bool AShader::LoadSource(std::string path)
{
	std::ifstream file(path);
	std::stringstream buf;

	if (!file.is_open()) return false;

	buf << file.rdbuf();
	_src = std::string(buf.str());
	_loaded = true;

	return true;
}
