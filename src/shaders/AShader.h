#pragma once

#include "common.h"
#include <string>

#include <iostream>
class AShader
{
public:
	AShader();
	virtual ~AShader() {}
	virtual bool LoadSource(std::string path);
	virtual bool Compile() = 0;

	bool isLoaded() { return _loaded; }
	GLuint getId() { return _id; }

	const std::string& getSrc() const { return _src; }

private:
	std::string _src;

protected:
	GLuint _id;
	bool _loaded;
	bool _compiled;
};

//class VertexShader : public IShader {
//public:
//	bool LoadSource(std::string path) override;
//};
