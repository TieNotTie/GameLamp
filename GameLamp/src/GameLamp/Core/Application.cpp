#include "pch.h"

#include "Application.h"

#include "GameLamp/Core/Core.h"
#include "GameLamp/Core/Window.h"
#include "GameLamp/Event/ApplicationEvent.h"
#include "GameLamp/Platform/Windows/WindowsWindow.h"

#include "glad/glad.h"

namespace GameLamp {

	Application::Application()
		: m_Window{std::unique_ptr<Window>(Window::create())}
	{
		m_Window->setEventCallback(GL_BIND_EVENT_FN(Application::onEvent));
	}

	Application::~Application() {}

	void Application::run()
	{
		WindowResizeEvent e(640, 640);

		GL_CORE_INFO(e);

	    while (m_Running) {
			glClearColor(0, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (auto layer : m_LayerStack)
			{
				layer->onUpdate();
			}

			m_Window->onUpdate();
		};
	}

	void Application::onEvent(Event& e)
	{
		EventDispatcher m_EventDispatcher(e);

		m_EventDispatcher.dispatch<WindowCloseEvent>(GL_BIND_EVENT_FN(Application::onWindowCloseEvent));
		m_EventDispatcher.dispatch<WindowResizeEvent>(GL_BIND_EVENT_FN(Application::onWindowResizeEvent));

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			if (e.Handled) break;
			(*it)->onEvent(e);
		}
	}

	void Application::pushLayer(Layer* layer)
	{
		m_LayerStack.pushLayer(layer);
	}

	void Application::pushOverlay(Layer* overlay)
	{
		m_LayerStack.pushOverlay(overlay);
	}

	bool Application::onWindowCloseEvent(WindowCloseEvent&)
	{
		m_Running = false;
		return true;
	}

	bool Application::onWindowResizeEvent(WindowResizeEvent& e)
	{
		return true;
	}

}  // namespace GameLamp
