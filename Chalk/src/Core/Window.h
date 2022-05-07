#pragma once

#include <string>
#include <memory>

struct GLFWwindow;

namespace Chalk
{
	class GraphicsContext;

	class Window
	{

	public:
		Window(const std::string& name, int width, int height);
		~Window();

		void Open();
		void Close();
		void Update();

		const std::string& GetName() const { return m_Name; }
		int GetWidth() const { return m_Width; }
		int GetHeight() const { return m_Width; }

	private:
		std::string m_Name;
		int m_Width;
		int m_Height;

		GLFWwindow* m_Handle;
		std::unique_ptr<GraphicsContext> m_GraphicsContext;
		bool m_IsOpen;

		static uint8_t s_WindowCount;
	};
}