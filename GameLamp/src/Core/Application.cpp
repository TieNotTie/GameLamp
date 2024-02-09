#include "Application.h"

#ifdef GL_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Lamp {

	extern bool g_IsRunning;

	Application::Application()
	{
#ifdef GL_PLATFORM_WINDOWS
		m_Window = Window::create();
#else
		assert(1 && "Platform not supported!")
#endif

	}

	int Application::run(int argc, char** argv)
	{
		// Main Game loop
		while (g_IsRunning)
		{
			// TODO: Add OpenGL update
			m_Window->tick();
			tick();
		}

		return 0;
	}

}
