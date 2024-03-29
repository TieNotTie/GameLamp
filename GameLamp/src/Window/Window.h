#pragma once
#include <string>

namespace Lamp {

	struct WindowProperties
	{
		std::string Name = "Game Lamp Engine";
		uint32_t Width = 1080, Height = 720;
		bool isVSync = false;
	};

	class Window
	{
	public:
		virtual ~Window() = default;

		virtual void tick(float delta = 0.0f) = 0;

		virtual uint32_t getWidth() const = 0;
		virtual uint32_t getHeight() const = 0;

		virtual void setWidth(uint32_t width) = 0;
		virtual void setHeight(uint32_t height) = 0;

		virtual bool isVSync() const = 0;
		virtual void setVSync(bool) = 0;

		virtual void* getNativeWindow() const = 0;

		static Window* create(const WindowProperties& props = WindowProperties());
	};

}

