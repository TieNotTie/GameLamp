#pragma once
#include "GameLamp/Core/Window.h"

struct GLFWwindow;

namespace GameLamp {

	class GraphicsContext;

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		virtual void onUpdate() override;

		virtual uint32_t getWidth() const override { return m_Data.Width; }
		virtual uint32_t getHeight() const override { return m_Data.Height; }

		virtual void setEventCallback(const EventCallback& callback) override { m_Data.s_EventCallback = callback; }
		virtual void setVSync(bool enabled) override;
		virtual bool isVSync() const override;

		inline virtual void* getNativeWindow() const override { return (void*)m_Window; }
		
	private:
		virtual void init(const WindowProps& props);
		virtual void shutdown();


	private:
		GLFWwindow* m_Window;
		GraphicsContext* m_Context;

		struct WindowData
		{
			std::string Title = "Default";
			uint32_t Width = 0, Height = 0;
			bool VSync = false;

			EventCallback s_EventCallback;
		};

		WindowData m_Data;
	};
}

