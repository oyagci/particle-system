#pragma once

class IRenderable
{
public:
	virtual ~IRenderable() {};
	virtual void OnRender() = 0;
};
