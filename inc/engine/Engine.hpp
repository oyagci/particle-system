#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class Engine
{
public:
	Engine(int width = 1280, int height = 720,
		std::string title = std::string("Particle System"));
	~Engine();

	int	Run();

	int GetWidth() { return _width; }
	int GetHeight() { return _height; }

	void SetTitle(std::string const title) { _title = title; }

private:
	void ProcessInputs();

private:
	bool _isRunning = false;
	GLFWwindow *_window;
	static int _width;
	static int _height;
	std::string _title;

	static void FramebufferResize(GLFWwindow *win, int width, int height);
};
