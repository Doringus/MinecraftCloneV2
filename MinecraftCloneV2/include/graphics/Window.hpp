#pragma once

#include <memory>

struct GLFWwindow;

namespace graphics {

class Window {
public:
	Window(size_t width, size_t height, const char* title);

	void pollEvents();
	void swapBuffers();
	bool shouldClose() const;
	void* getNativeHandle() const noexcept;
	void disableCursor();
private:
	size_t m_Width, m_Height;
	std::unique_ptr<GLFWwindow, void(*)(GLFWwindow*)> m_Window;
};

}
