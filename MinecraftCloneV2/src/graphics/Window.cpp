#include <graphics/Window.hpp>
#include <GLFW/glfw3.h>
#include <stdexcept>

namespace graphics {

Window::Window(size_t width, size_t height, const char* title) : 
	m_Width{ width }, m_Height{ height },
	m_Window{ glfwCreateWindow(m_Width, m_Height, title, nullptr, nullptr), glfwDestroyWindow } {
	if (!m_Window) {
		throw std::runtime_error("Cannot create glfw window");
	}
}

void Window::pollEvents() {
	glfwPollEvents();
}

void Window::swapBuffers() {
	glfwSwapBuffers(m_Window.get());
}

bool Window::shouldClose() const {
	return glfwWindowShouldClose(m_Window.get());
}

void* Window::getNativeHandle() const noexcept {
	return m_Window.get();
}

void Window::disableCursor() {
	glfwSetInputMode(m_Window.get(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

}