#pragma once

#include "Event.h"

namespace GameLamp {

	class GL_API MouseMovedEvent final : public Event
	{
	public:
		MouseMovedEvent(double x, double y)
			:m_X{x}, m_Y{y}
		{}

		double getX() const { return m_X; }
		double getY() const { return m_Y; }

		virtual std::string getDebugInfo() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_X << ", " << m_Y;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);

	private:
		double m_X, m_Y;
	};


	class GL_API MouseScrolledEvent final : public Event{
	public:
		MouseScrolledEvent(double xOffset, double yOffset)
			:m_XOffset{xOffset}, m_YOffset{yOffset}
		{}

		double getXOffset() const { return m_XOffset; }
		double getYOffset() const { return m_YOffset; }

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	private:
		double m_XOffset, m_YOffset;
	};

	class GL_API MouseButtonEvent : public Event
	{
	public:
		uint16_t getMouseButton() const { return m_MouseButton; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

	protected:
		MouseButtonEvent(uint16_t mouseButton)
			:m_MouseButton{mouseButton}
		{}
		uint16_t m_MouseButton;
	};

	class GL_API MouseButtonPressedEvent final : public MouseButtonEvent{
	public: 
		MouseButtonPressedEvent(uint16_t mouseButton)
			:MouseButtonEvent{mouseButton}
		{}

		virtual std::string getDebugInfo() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_MouseButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class GL_API MouseButtonReleasedEvent final : public MouseButtonEvent{
	public:
		MouseButtonReleasedEvent(uint16_t mouseButton)
			:MouseButtonEvent{mouseButton}
		{}

		virtual std::string getDebugInfo() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_MouseButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
