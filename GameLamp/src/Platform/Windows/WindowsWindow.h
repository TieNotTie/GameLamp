#pragma once

#include "Window/Window.h"

//#include "Event/EventDispatcher.h"
#include "Input/PlatformInputEventHandler.h"

struct GLFWwindow;

namespace Lamp {

	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();

		virtual void tick(double delta = 0.0) override;
		virtual void closeWindow() override;

		virtual uint32_t getWidth() const override;
		virtual uint32_t getHeight() const override;

		virtual void setWidth(uint32_t width) override;
		virtual void setHeight(uint32_t height) override;

		virtual bool isVSync() const override;
		virtual void setVSync(bool) override;

		virtual bool isConsoleEnabled() const override;
		virtual void enableConsole(bool) override;

		virtual void* getNativeWindow() const override;

		virtual struct Position2D getMousePosition() const override;
		virtual void setMousePosition(struct Position2D) override;

	private:
		void init(const WindowProperties& props);
		void shutdown();

	private:
		GLFWwindow* m_Window;

		WindowProperties m_WindowProperties;

	private:

		struct WindowData
		{
			std::shared_ptr<PlatformInputEventHandler> PlatfromInputHandler;
		};

		WindowData m_WindowData;
	};

}
