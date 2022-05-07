#pragma once

#include <string>
#include <memory>

namespace Chalk
{
	class Window;

	struct Settings
	{
		std::string ApplicationName;
		std::string WindowName;
		int WindowWidth;
		int WindowHeight;
	};

	class Application
	{
	public:
		Application(const Settings& settings);
		virtual ~Application();

		void Start();
		void Stop();

		static Application& GetInstance() { return *s_Instance; }

	private:
		std::string m_Name;

		bool m_IsRunning;
		std::unique_ptr<Window> m_Window;

		static Application* s_Instance;
	};
}