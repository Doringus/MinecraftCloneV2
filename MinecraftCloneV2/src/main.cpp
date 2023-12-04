#include <graphics/SingleWindowContext.hpp>
#include <graphics/Window.hpp>

int main() {
	graphics::SingleWindowContext context{ graphics::contextParams_t{
		.versionMajor = 4,
		.versionMinor = 5,
		.openglProfile = GLFW_OPENGL_CORE_PROFILE,
		.experimental = true
	},
	graphics::windowParams_t{
		.width = 640,
		.height = 480,
		.name = "Minecraft"
	} };
	
	glViewport(0, 0, 640, 480);

	while (!context.getWindow().shouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		context.getWindow().pollEvents();
		context.getWindow().swapBuffers();
	}

    return 0;
}