#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <graphics/Window.hpp>
#include <optional>

namespace graphics {

struct contextParams_t {
	int versionMajor;
	int versionMinor;
	int openglProfile;
	bool experimental;
};

struct windowParams_t {
	size_t width;
	size_t height;
	const char* name;
};

class SingleWindowContext final {
public:
	SingleWindowContext(const contextParams_t& contextParams, const windowParams_t& windowParams);
	~SingleWindowContext();

	Window& getWindow() noexcept;
	const Window& getWindow() const noexcept;
private:
	std::optional<Window> m_Window;
};

}