#pragma once

#include "common.h"
#include <string>
#include <vector>
#include "IRenderable.h"

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

	void AddRenderable(IRenderable *r);

private:
	void ProcessInputs();
	void Render();

private:
	bool _isRunning = false;
	GLFWwindow *_window;
	static int _width;
	static int _height;
	std::string _title;
	std::vector<IRenderable*> _renderables;

	static void FramebufferResize(GLFWwindow *win, int width, int height);

public:
	class InvalidWindowSize : public std::exception {
		const char *what() const noexcept {
			return "Specified window size is either too big or too small or negative";
		}
	};

	class GLFWLoadingError : public std::exception {
	public:
		const char *what() const noexcept {
			const char *description = nullptr;

			glfwGetError(&description);
			return description;
		}
	};

	class GLEWLoadingError : public std::exception {
	private:
		GLenum _errcode;
	public:
		GLEWLoadingError(GLenum errcode) {
			_errcode = errcode;
		}
		const char *what() const noexcept {
			GLubyte const *err = glewGetErrorString(_errcode);
			return reinterpret_cast<const char*>(err);
		}
	};
};
