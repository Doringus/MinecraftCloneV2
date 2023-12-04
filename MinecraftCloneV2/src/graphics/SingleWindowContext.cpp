#include <graphics/SingleWindowContext.hpp>
#include <stdexcept>
#include <iostream>

namespace graphics {

SingleWindowContext::SingleWindowContext(const contextParams_t& contextParams, const windowParams_t& windowParams) {
	if (int result = glfwInit(); result != GLFW_TRUE) {
		throw std::runtime_error("Cannot init glfw");
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, contextParams.versionMajor);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, contextParams.versionMinor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, contextParams.openglProfile);
	/// need to glfwMakeContextCurrent BEFORE glewInit
	m_Window = std::make_optional<Window>(windowParams.width, windowParams.height, windowParams.name);
	glfwMakeContextCurrent(static_cast<GLFWwindow*>(m_Window.value().getNativeHandle()));
	glewExperimental = contextParams.experimental;
	if (GLenum result = glewInit(); result != GLEW_OK) {
		std::cout << glewGetErrorString(result);
		throw std::runtime_error("Cannot init glew");
	}
}

SingleWindowContext::~SingleWindowContext() {
	glfwTerminate();
}

Window& SingleWindowContext::getWindow() noexcept {
	return m_Window.value();
}

const Window& SingleWindowContext::getWindow() const noexcept {
	return m_Window.value();
}

}