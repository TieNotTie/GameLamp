#include "pch.h"

#include "Application.h"

#include "GameLamp/Core/Window.h"
#include "GameLamp/Platform/Windows/WindowsWindow.h"

#include "GLFW/glfw3.h"

namespace GameLamp {

	Application::Application()
		: m_Window{ std::unique_ptr<Window>(Window::create())}
	{
		
	}

	Application::~Application() {}

	void Application::run()
	{

	    while (m_Running) {
			glClearColor(0, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->onUpdate();
		};
	}

}  // namespace GameLamp
