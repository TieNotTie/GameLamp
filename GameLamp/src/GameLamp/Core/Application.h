#pragma once
#include "pch.h"

#include "GameLamp/Core/Core.h"
#include "GameLamp/Core/LayerStack.h"
#include "GameLamp/Core/Timestep.h"
#include "GameLamp/Core/Window.h"
#include "GameLamp/Event/Event.h"
#include "GameLamp/Event/ApplicationEvent.h"
#include "GameLamp/ImGui/ImGuiLayer.h"
#include "GameLamp/Renderer/Shader.h"
#include "GameLamp/Renderer/Buffer.h"
#include "GameLamp/Renderer/VertexArray.h"

namespace GameLamp {

	class Window;

	struct ApplicationSpecification
	{
		ApplicationSpecification(std::string name, uint32_t width, uint32_t height)
			: Name{name}, Width{width}, Height{height}
		{}
		std::string Name;
		uint32_t Width = 0, Height = 0;
	}; 

	class GL_API Application {
	public:
	    Application(const ApplicationSpecification&);
	    virtual ~Application();
	    void run();
		void onEvent(Event& e);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* overlay);

		inline Window& getWindow() { return *m_Window; }
		static inline Application& get() { return *s_Instance; }

	private:
		bool onWindowCloseEvent(WindowCloseEvent& e);
		bool onWindowResizeEvent(WindowResizeEvent& e);

	private:
		bool m_Running {true};
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		ApplicationSpecification m_Specification;
		static Application* s_Instance;

	};

	// HAS TO BE DEFINED IN CLIENT APP!
	Application* CreateApplication();

}  // namespace GameLamp
