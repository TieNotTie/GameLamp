#include "pch.h"

#include "Application.h"

#include "GameLamp/Core/Core.h"
#include "GameLamp/Core/Input.h"
#include "GameLamp/Core/Window.h"
#include "GameLamp/Event/ApplicationEvent.h"
#include "GameLamp/Platform/Windows/WindowsWindow.h"
#include "GameLamp/ImGui/ImGuiLayer.h"
#include "GameLamp/Renderer/Renderer.h"

#include <GLFW/glfw3.h>

namespace GameLamp {

	Application* Application::s_Instance = nullptr;

	Application::Application(const ApplicationSpecification& spec)
		: m_Specification{spec}
		, m_Window{std::unique_ptr<Window>(Window::create(WindowProps(spec.Name, spec.Width, spec.Height)))}
	{
		GL_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window->setEventCallback(GL_BIND_EVENT_FN(Application::onEvent));

		m_ImGuiLayer = new ImGuiLayer();
		pushOverlay(m_ImGuiLayer);
	}

	Application::~Application()
	{
	}

	void Application::run()
	{
	    while (m_Running) {
			float time = (float)glfwGetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			for (Layer* layer : m_LayerStack)
				layer->onUpdate(timestep);

			m_ImGuiLayer->begin();
			for (Layer* layer : m_LayerStack)
				layer->onImGuiRender();
			m_ImGuiLayer->end();

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
