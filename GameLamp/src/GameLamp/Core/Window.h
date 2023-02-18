#pragma once

#include "pch.h"

namespace GameLamp
{
	struct WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string& title = "GameLamp engine",
			uint32_t width = 1280, uint32_t height = 720)
			: Title{title}, Width{width}, Height{height}
		{}
	};

	class GL_API Event;

	class GL_API Window
	{
	public:
		using EventCallback = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void onUpdate() = 0;

		virtual uint32_t getWidth() const = 0;
		virtual uint32_t getHeight() const = 0;

		virtual void setEventCallback(const EventCallback& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		virtual void* getNativeWindow() const = 0;

		static Window* create(const WindowProps& props = WindowProps());
	};

}
