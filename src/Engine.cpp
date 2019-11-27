#include "engine/Engine.hpp"
#include <iostream>

int Engine::_width = 1280;
int Engine::_height = 720;

Engine::Engine(int width, int height, std::string title) :_title(title)
{
	if (glfwInit() != GLFW_TRUE) {
		throw new std::exception();
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

	_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (nullptr == _window) {
		const char *description = NULL;

		glfwGetError(&description);
		std::cerr << description << std::endl;

		throw new std::exception();
	}

	glfwMakeContextCurrent(_window);
	glfwSetFramebufferSizeCallback(_window, Engine::FramebufferResize);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		std::cerr << "GLEW: " << glewGetErrorString(err) << std::endl;
		throw new std::exception();
	}

	glViewport(0, 0, _width, _height);
	glEnable(GL_DEPTH_TEST);
}

Engine::~Engine()
{
	glfwDestroyWindow(_window);
	glfwTerminate();
}

int	Engine::Run()
{
	_isRunning = true;

	while (_isRunning) {
		glfwPollEvents();
		glfwSwapBuffers(_window);

		ProcessInputs();
		_isRunning = !glfwWindowShouldClose(_window);
	}
	return (0);
}

void Engine::FramebufferResize(GLFWwindow *, int width, int height)
{
	_width = width;
	_height = height;
	glViewport(0, 0, width, height);
}

void Engine::ProcessInputs()
{
	if (glfwGetKey(_window, GLFW_KEY_ESCAPE)) {
		glfwSetWindowShouldClose(_window, GLFW_TRUE);
	}
}
