#pragma once

#include "AShader.h"

class VertexShader : public AShader
{
public:
	VertexShader();
	~VertexShader() override;

	bool Compile() override;
};
