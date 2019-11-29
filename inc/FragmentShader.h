#pragma once

#include "AShader.h"

class FragmentShader : public AShader
{
public:
	FragmentShader();
	~FragmentShader() override;

	bool Compile() override;
};
