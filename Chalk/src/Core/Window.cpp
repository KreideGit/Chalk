#include "Window.h"

#include <assert.h>
#include <GLFW/glfw3.h>
#include "Rendering/GraphicsContext.h"

using namespace Chalk;

uint8_t Window::s_WindowCount = 0;

Window::Window(const std::string& name, int width, int height) 
	: m_Name(name), m_Width(width), m_Height(height), m_Handle(nullptr), m_IsOpen(false)
{
	if(s_WindowCount == 0)
	{
		int initialized = glfwInit();
		assert(initialized == GLFW_TRUE);
	}
}

Window::~Window()
{
	Close();
}

void Window::Open()
{
	if(m_IsOpen)
	{
		return;
	}

	m_Handle = glfwCreateWindow(m_Width, m_Height, m_Name.c_str(), nullptr, nullptr);
	assert(m_Handle != nullptr);

	m_GraphicsContext = std::make_unique<GraphicsContext>(m_Handle);
	m_GraphicsContext->Initialize();

	m_IsOpen = true;
	s_WindowCount++;
}

void Window::Close()
{
	if(!m_IsOpen)
	{
		return;
	}

	glfwDestroyWindow(m_Handle);
	m_IsOpen = false;

	s_WindowCount--;
	if (s_WindowCount == 0)
	{
		glfwTerminate();
	}
}

void Window::Update()
{
	glfwSwapBuffers(m_Handle);
	glfwPollEvents();
}