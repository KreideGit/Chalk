#include "GraphicsContext.h"

#include <assert.h>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

using namespace Chalk;

GraphicsContext::GraphicsContext(GLFWwindow* windowHandle)
	: m_WindowHandle(windowHandle)
{
}

void Chalk::GraphicsContext::Initialize()
{
	glfwMakeContextCurrent(m_WindowHandle);
	int initialized = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	assert(initialized);
}