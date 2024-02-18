#include "Application.h"

#if GL_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

#include "Core/Core.h"
#include "Core/Log.h"
#include "Util/Time.h"

namespace Lamp {

	extern bool g_IsRunning;

	Application::Application()
	{
		m_Window = Window::create();
		bool result = CoreInit();

		GL_CORE_ASSERT(result && "Failed to init core modules");
	}

	int Application::run(int argc, char** argv)
	{
		double delta = .0f;

		// Main Game loop
		while (g_IsRunning)
		{
			UpdateDeltaTime();
			delta = GetDeltaTime();

			tickInternal(delta);
			tick(delta);
		}

		return 0;
	}

	void Application::tickInternal(double delta)
	{
		// TODO: Add OpenGL update
		m_Window->tick(delta);
	}

}
