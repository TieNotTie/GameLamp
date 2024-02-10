#include "Application.h"

#ifdef GL_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

#include "Core/Core.h"

namespace Lamp {

	extern bool g_IsRunning;

	Application::Application()
	{
		m_Window = Window::create();
		CoreInit();
	}

	int Application::run(int argc, char** argv)
	{
		float delta = .0f;
		// Main Game loop
		while (g_IsRunning)
		{
			tickInternal(delta);
			tick(delta);
		}

		return 0;
	}

	void Application::tickInternal(float delta)
	{
		// TODO: Add OpenGL update
		m_Window->tick(delta);
	}

}
