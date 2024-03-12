#pragma once
#include <string>

namespace Lamp {

	using WindowId_t = uint32_t;

	struct WindowProperties
	{

		std::string Name = "Game Lamp Engine";
		uint32_t Width = 1080, Height = 720;
		bool isVSync = false;
		bool isConsoleEnabled = true;
	};

	class Window
	{
	public:
		Window() = default;
		virtual ~Window() = default;

		virtual void tick(double delta = 0.0) = 0;

		virtual void closeWindow() = 0;

		virtual uint32_t getWidth() const = 0;
		virtual uint32_t getHeight() const = 0;

		virtual void setWidth(uint32_t width) = 0;
		virtual void setHeight(uint32_t height) = 0;

		virtual bool isVSync() const = 0;
		virtual void setVSync(bool) = 0;

		virtual bool isConsoleEnabled() const = 0;
		virtual void enableConsole(bool) = 0;

		virtual void* getNativeWindow() const = 0;

		virtual struct Position2D getMousePosition() const = 0;
		virtual void setMousePosition(struct Position2D) = 0;

		static Window* create(const WindowProperties& props = WindowProperties());

	};

}

