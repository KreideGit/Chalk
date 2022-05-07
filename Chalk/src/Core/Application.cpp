#include "Application.h"

#include <assert.h>
#include "glad/glad.h"
#include "Window.h"

using namespace Chalk;

Application* Application::s_Instance = nullptr;

Application::Application(const Settings& settings)
	: m_Name(settings.ApplicationName), m_IsRunning(false)
{
	assert(s_Instance == nullptr);
	s_Instance = this;

	m_Window = std::make_unique<Window>(settings.WindowName, settings.WindowWidth, settings.WindowHeight);
}

Application::~Application()
{
}

void Application::Start()
{
	m_IsRunning = true;

	m_Window->Open();

	while(m_IsRunning)
	{
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		m_Window->Update();
	}

	m_Window->Close();
}

void Application::Stop()
{
	m_IsRunning = false;
}