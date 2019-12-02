#include "engine/Engine.hpp"
#include <iostream>

int Engine::_width = 1280;
int Engine::_height = 720;

Engine::Engine(int width, int height, std::string title) :_title(title)
{
	if (width < 0 || height < 0) throw InvalidWindowSize();
	if (glfwInit() != GLFW_TRUE) throw GLFWLoadingError();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

	_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (nullptr == _window) {
		throw GLFWLoadingError();
	}

	glfwMakeContextCurrent(_window);
	glfwSetFramebufferSizeCallback(_window, Engine::FramebufferResize);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		throw GLEWLoadingError(err);
	}

	glViewport(0, 0, _width, _height);
//	glEnable(GL_DEPTH_TEST);
	glEnable(GL_PROGRAM_POINT_SIZE);
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

		Render();
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

void Engine::AddRenderable(std::unique_ptr<IRenderable> r)
{
	_renderables.push_back(std::move(r));
}

void Engine::Render()
{
	glClearColor(.1f, .1f, .1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (auto &renderable : _renderables) {
		renderable->OnRender();
	}
	glfwSwapBuffers(_window);
}
