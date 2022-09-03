#pragma once
#include "pch.h"

#include "Core.h"

namespace GameLamp {

	class Window;

	class GL_API Application {
	public:
	    Application();
	    virtual ~Application();

	    void run();
	private:
		bool m_Running {true};
		std::unique_ptr<Window> m_Window;
	};

	// HAS TO BE DEFINED IN CLIENT APP!
	Application* CreateApplication();

}  // namespace GameLamp
