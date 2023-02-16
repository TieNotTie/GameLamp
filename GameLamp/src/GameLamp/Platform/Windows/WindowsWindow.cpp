#include "pch.h"
#include "WindowsWindow.h"

#include "GameLamp/Event/ApplicationEvent.h"
#include "GameLamp/Event/KeyEvent.h"
#include "GameLamp/Event/MouseEvent.h"

namespace GameLamp {

	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* message)
	{
		GL_CORE_ERROR("GLFW Error ({0}): {1}", error, message);
	}

	Window* Window::create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		shutdown();
	}

	void WindowsWindow::init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		GL_CORE_INFO("Creating window {0}, ({1}, {2})", m_Data.Title, m_Data.Width, m_Data.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			GL_CORE_ASSERT(success, "Could not initialize GLFW!");

			s_GLFWInitialized = true;
		}

		glfwSetErrorCallback(GLFWErrorCallback);
		
		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, (void*)&m_Data);
		setVSync(true);

		//Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				WindowResizeEvent e(width, height);
				data.s_EventCallback(e);
			}
		);

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				WindowCloseEvent e;
				data.s_EventCallback(e);
			}
		);

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent e(key, 0);
						data.s_EventCallback(e);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent e(key);
						data.s_EventCallback(e);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent e(key, 1);
						data.s_EventCallback(e);
						break;
					}
				};

			}
		);

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				
				switch (action)
					{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent e(button);
						data.s_EventCallback(e);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent e(button);
						data.s_EventCallback(e);
						break;
					}
				};

			}
		);

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent e(xoffset, yoffset);
				data.s_EventCallback(e);
			}
		);

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				
				MouseMovedEvent e(xpos, ypos);
				data.s_EventCallback(e);
			}
		);
	}

	void WindowsWindow::shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::setVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::isVSync() const
	{
		return m_Data.VSync;
	}

}
