#pragma once

struct GLFWwindow;

namespace Chalk
{
	class GraphicsContext
	{

	public:
		GraphicsContext(GLFWwindow* windowHandle);

		void Initialize();

	private:
		GLFWwindow* m_WindowHandle;

	};
}