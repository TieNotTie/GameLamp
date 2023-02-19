#pragma once
#include "pch.h"

#include "GameLamp/Core/Core.h"
#include "GameLamp/Core/LayerStack.h"
#include "GameLamp/Core/Window.h"
#include "GameLamp/Event/Event.h"
#include "GameLamp/Event/ApplicationEvent.h"
#include "GameLamp/ImGui/ImGuiLayer.h"
#include "GameLamp/Renderer/Shader.h"
#include "GameLamp/Renderer/Buffer.h"

namespace GameLamp {

	class Window;

	class GL_API Application {
	public:
	    Application();
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
	private:
		static Application* s_Instance;
		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
	};

	// HAS TO BE DEFINED IN CLIENT APP!
	Application* CreateApplication();

}  // namespace GameLamp
