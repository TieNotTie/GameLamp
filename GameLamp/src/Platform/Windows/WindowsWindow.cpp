#include "WindowsWindow.h"

#include <GLFW/glfw3.h>

#include <cassert>

namespace Lamp {
	Window* Window::create(const WindowProperties& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& props)
		: m_WindowProperties{props}
	{
		init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		shutdown();
	}

	void WindowsWindow::tick(float delta /*= 0.0f*/)
	{
		glClearColor(16.0f / 255.0f, 76.0f / 255.0f, 145.0f / 255.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(m_Window);

		glfwPollEvents();
	}

	uint32_t WindowsWindow::getWidth() const
	{
		return m_WindowProperties.Width;
	}

	uint32_t WindowsWindow::getHeight() const
	{
		return m_WindowProperties.Height;
	}

	void WindowsWindow::setWidth(uint32_t width)
	{
		m_WindowProperties.Width = width;
	}

	void WindowsWindow::setHeight(uint32_t height)
	{
		m_WindowProperties.Height = height;
	}

	bool WindowsWindow::isVSync() const
	{
		return m_WindowProperties.isVSync;
	}

	void WindowsWindow::setVSync(bool enableVSync)
	{
		m_WindowProperties.isVSync = enableVSync;
	}

	void* WindowsWindow::getNativeWindow() const
	{
		return (void*)m_Window;
	}

	void WindowsWindow::init(const WindowProperties& props)
	{
		if (!glfwInit()) assert(0 && "Failed to initialize GLFW");

		m_Window = glfwCreateWindow(props.Width, props.Height, props.Name.c_str(), nullptr, nullptr);

		if (!m_Window)
		{
			glfwTerminate();
			assert(1 && "Failed to create a window!");
		}

		glfwMakeContextCurrent(m_Window);

	}

	void WindowsWindow::shutdown()
	{
		glfwTerminate();
	}

}
