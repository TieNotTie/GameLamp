#pragma once

#include "GameLamp/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace GameLamp {

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void init() override;
		virtual void swapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};

} // namespace GameLamp 
