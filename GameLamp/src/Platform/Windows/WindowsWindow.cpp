#include "WindowsWindow.h"

#include "Core/Log.h"
#include "Input/InputCoreTypes.h"
#include "Input/SlateApplicationInput.h"
#include "Util/Position.h"

#include <GLFW/glfw3.h>

#include <Windows.h>

#include <array>
#include <map>

namespace Lamp {

	namespace WindowsPlatfromInput
	{

		const Key getKey(int glfwIndex)
		{
			switch (glfwIndex)
			{
				case GLFW_KEY_SPACE: return EKeys::SpaceBar;
				case GLFW_KEY_APOSTROPHE: return EKeys::Apostrophe;
				case GLFW_KEY_COMMA: return EKeys::Comma;
				case GLFW_KEY_MINUS: return EKeys::Subtract;
				case GLFW_KEY_PERIOD: return EKeys::Period;
				case GLFW_KEY_SLASH: return EKeys::Slash;
				case GLFW_KEY_0: return EKeys::Zero;
				case GLFW_KEY_1: return EKeys::One;
				case GLFW_KEY_2: return EKeys::Two;
				case GLFW_KEY_3: return EKeys::Three;
				case GLFW_KEY_4: return EKeys::Four;
				case GLFW_KEY_5: return EKeys::Five;
				case GLFW_KEY_6: return EKeys::Six;
				case GLFW_KEY_7: return EKeys::Seven;
				case GLFW_KEY_8: return EKeys::Eight;
				case GLFW_KEY_9: return EKeys::Nine;
				case GLFW_KEY_SEMICOLON: return EKeys::Semicolon;
				case GLFW_KEY_EQUAL: return EKeys::Equals;
				case GLFW_KEY_A: return EKeys::A;
				case GLFW_KEY_B: return EKeys::B;
				case GLFW_KEY_C: return EKeys::C;
				case GLFW_KEY_D: return EKeys::D;
				case GLFW_KEY_E: return EKeys::E;
				case GLFW_KEY_F: return EKeys::F;
				case GLFW_KEY_G: return EKeys::G;
				case GLFW_KEY_H: return EKeys::H;
				case GLFW_KEY_I: return EKeys::I;
				case GLFW_KEY_J: return EKeys::J;
				case GLFW_KEY_K: return EKeys::K;
				case GLFW_KEY_L: return EKeys::L;
				case GLFW_KEY_M: return EKeys::M;
				case GLFW_KEY_N: return EKeys::N;
				case GLFW_KEY_O: return EKeys::O;
				case GLFW_KEY_P: return EKeys::P;
				case GLFW_KEY_Q: return EKeys::Q;
				case GLFW_KEY_R: return EKeys::R;
				case GLFW_KEY_S: return EKeys::S;
				case GLFW_KEY_T: return EKeys::T;
				case GLFW_KEY_U: return EKeys::U;
				case GLFW_KEY_V: return EKeys::V;
				case GLFW_KEY_W: return EKeys::W;
				case GLFW_KEY_X: return EKeys::X;
				case GLFW_KEY_Y: return EKeys::Y;
				case GLFW_KEY_Z: return EKeys::Z;
				case GLFW_KEY_LEFT_BRACKET: return EKeys::LeftBracket;
				case GLFW_KEY_BACKSLASH: return EKeys::Backslash;
				case GLFW_KEY_RIGHT_BRACKET: return EKeys::RightBracket;
				case GLFW_KEY_ESCAPE: return EKeys::Escape;
				case GLFW_KEY_ENTER: return EKeys::Enter;
				case GLFW_KEY_TAB: return EKeys::Tab;
				case GLFW_KEY_BACKSPACE: return EKeys::BackSpace;
				case GLFW_KEY_INSERT: return EKeys::Insert;
				case GLFW_KEY_DELETE: return EKeys::Delete;
				case GLFW_KEY_RIGHT: return EKeys::Right;
				case GLFW_KEY_LEFT: return EKeys::Left;
				case GLFW_KEY_DOWN: return EKeys::Down;
				case GLFW_KEY_UP: return EKeys::Up;
				case GLFW_KEY_PAGE_UP: return EKeys::PageUp;
				case GLFW_KEY_PAGE_DOWN: return EKeys::PageDown;
				case GLFW_KEY_HOME: return EKeys::Home;
				case GLFW_KEY_END: return EKeys::End;
				case GLFW_KEY_CAPS_LOCK: return EKeys::CapsLock;
				case GLFW_KEY_SCROLL_LOCK: return EKeys::ScrollLock;
				case GLFW_KEY_NUM_LOCK: return EKeys::NumLock;
				case GLFW_KEY_PRINT_SCREEN: return EKeys::PrintScreen;
				case GLFW_KEY_PAUSE: return EKeys::Pause;
				case GLFW_KEY_F1: return EKeys::F1;
				case GLFW_KEY_F2: return EKeys::F2;
				case GLFW_KEY_F3: return EKeys::F3;
				case GLFW_KEY_F4: return EKeys::F4;
				case GLFW_KEY_F5: return EKeys::F5;
				case GLFW_KEY_F6: return EKeys::F6;
				case GLFW_KEY_F7: return EKeys::F7;
				case GLFW_KEY_F8: return EKeys::F8;
				case GLFW_KEY_F9: return EKeys::F9;
				case GLFW_KEY_F10: return EKeys::F10;
				case GLFW_KEY_F11: return EKeys::F11;
				case GLFW_KEY_F12: return EKeys::F12;
				case GLFW_KEY_KP_0: return EKeys::NumPadZero;
				case GLFW_KEY_KP_1: return EKeys::NumPadOne;
				case GLFW_KEY_KP_2: return EKeys::NumPadTwo;
				case GLFW_KEY_KP_3: return EKeys::NumPadThree;
				case GLFW_KEY_KP_4: return EKeys::NumPadFour;
				case GLFW_KEY_KP_5: return EKeys::NumPadFive;
				case GLFW_KEY_KP_6: return EKeys::NumPadSix;
				case GLFW_KEY_KP_7: return EKeys::NumPadSeven;
				case GLFW_KEY_KP_8: return EKeys::NumPadEight;
				case GLFW_KEY_KP_9: return EKeys::NumPadNine;
				case GLFW_KEY_KP_DECIMAL: return EKeys::Decimal;
				case GLFW_KEY_KP_DIVIDE: return EKeys::Divide;
				case GLFW_KEY_KP_MULTIPLY: return EKeys::Multiply;
				case GLFW_KEY_KP_SUBTRACT: return EKeys::Subtract;
				case GLFW_KEY_KP_ADD: return EKeys::Add;
				case GLFW_KEY_KP_ENTER: return EKeys::Enter;
				case GLFW_KEY_KP_EQUAL: return EKeys::Equals;
				case GLFW_KEY_LEFT_SHIFT: return EKeys::LeftShift;
				case GLFW_KEY_LEFT_CONTROL: return EKeys::LeftControl;
				case GLFW_KEY_LEFT_ALT: return EKeys::LeftAlt;
				case GLFW_KEY_LEFT_SUPER: return EKeys::LeftCommand;
				case GLFW_KEY_RIGHT_SHIFT: return EKeys::RightShift;
				case GLFW_KEY_RIGHT_CONTROL: return EKeys::RightControl;
				case GLFW_KEY_RIGHT_ALT: return EKeys::RightAlt;
				case GLFW_KEY_RIGHT_SUPER: return EKeys::RightCommand;
				case GLFW_KEY_MENU: return EKeys::Menu;
				case GLFW_MOUSE_BUTTON_LEFT: return EKeys::MouseLeftButton;
				case GLFW_MOUSE_BUTTON_MIDDLE: return EKeys::MouseMiddleButton;
				case GLFW_MOUSE_BUTTON_RIGHT: return EKeys::MouseRightButton;
				case GLFW_MOUSE_BUTTON_4: return EKeys::MouseThumbButton0;
				case GLFW_MOUSE_BUTTON_5: return EKeys::MouseThumbButton1;
				default: return EKeys::Invalid;
			}
		}

		const ButtonStates getState(int action)
		{
			switch (action)
			{
			case GLFW_PRESS: return ButtonStates::Pressed;
			case GLFW_RELEASE: return ButtonStates::Released;
			case GLFW_REPEAT: return ButtonStates::Hold;
			default: return ButtonStates::Invalid;
			}
		}
	}

	/* Windows input event handler*/
	class WindowsPlatformInputEventHandler : public PlatformInputEventHandler
	{
	public:
		WindowsPlatformInputEventHandler() = default;

		virtual void onKeyEvent(int key, int action, int) override
		{
			const Key LampKey = WindowsPlatfromInput::getKey(key);
			const ButtonStates state = WindowsPlatfromInput::getState(action);

			m_SlateInputEventHandler->onKeyEvent(LampKey, state);
		}
		virtual void onMouseButtonEvent(int button, int action, int) override
		{
			const Key LampKey = WindowsPlatfromInput::getKey(button);
			const ButtonStates state = WindowsPlatfromInput::getState(action);

			m_SlateInputEventHandler->onMouseButtonEvent(LampKey, state);
		}
		virtual void onMouseMovedEvent(double x, double y) override
		{
			Position2D currentPosition{x, y};

			m_SlateInputEventHandler->onMouseMoved(currentPosition);
		}
		virtual void onMouseWheelScrolledEvent(double yOffset) override
		{
			m_SlateInputEventHandler->onMouseWheelScrolledEvent(yOffset);
		}
	};

	std::shared_ptr<PlatformInputEventHandler> PlatformInputEventHandler::GetPlatfromEventHandler()
	{
		static std::shared_ptr< PlatformInputEventHandler> EventHandler = std::make_shared<WindowsPlatformInputEventHandler>();

		return EventHandler;
	}

	/* Windows Window*/
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

	void WindowsWindow::tick(double delta)
	{
		glClearColor(16.0f / 255.0f, 76.0f / 255.0f, 145.0f / 255.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(m_Window);

		glfwPollEvents();
	}

	void WindowsWindow::closeWindow()
	{
		shutdown();
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
		glfwSwapInterval((int)enableVSync);
		m_WindowProperties.isVSync = enableVSync;
	}

	bool WindowsWindow::isConsoleEnabled() const
	{
		return m_WindowProperties.isConsoleEnabled;
	}

	void WindowsWindow::enableConsole(bool enable)
	{
		if (m_WindowProperties.isConsoleEnabled == enable) return;
		
		enable == true ? AllocConsole() : FreeConsole();

		m_WindowProperties.isConsoleEnabled = enable;
	}

	void* WindowsWindow::getNativeWindow() const
	{
		return (void*)m_Window;
	}

	Position2D WindowsWindow::getMousePosition() const
	{
		Position2D result;
		glfwGetCursorPos(m_Window, &result.X, &result.Y);

		return result;
	}

	void WindowsWindow::setMousePosition(Position2D pos)
	{
		glfwGetCursorPos(m_Window, &pos.X, &pos.Y);
	}

	void WindowsWindow::init(const WindowProperties& props)
	{
		if (props.isConsoleEnabled) AllocConsole();

		GL_CORE_ASSERT((glfwInit() == GLFW_TRUE) && "Failed to initialize GLFW");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

		m_Window = glfwCreateWindow(props.Width, props.Height, props.Name.c_str(), nullptr, nullptr);

		if (!m_Window)
		{
			shutdown();
			GL_CORE_ASSERT(0 && "Failed to create a window!")
		}
		glfwMakeContextCurrent(m_Window);
		glfwSetInputMode(m_Window, GLFW_LOCK_KEY_MODS, GLFW_TRUE);

		m_WindowData.PlatfromInputHandler = PlatformInputEventHandler::GetPlatfromEventHandler();

		glfwSetWindowUserPointer(m_Window, (void*)&m_WindowData);

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) 
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
				data->PlatfromInputHandler->onKeyEvent(key, action, mods);
			});
	
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double, double yoffset) 
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
				data->PlatfromInputHandler->onMouseWheelScrolledEvent(yoffset);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
				data->PlatfromInputHandler->onMouseMovedEvent(xpos, ypos);
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) 
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
				data->PlatfromInputHandler->onMouseButtonEvent(button, action, mods);
			});

	}

	void WindowsWindow::shutdown()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

}
