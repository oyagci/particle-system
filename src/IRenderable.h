#pragma once

class IRenderable
{
public:
	virtual ~IRenderable() = 0;
	virtual void OnRender() = 0;
};
