#pragma once

#include "pch.h"

#include "GameLamp/Core/Base.h"
#include "GameLamp/Core/Core.h"

namespace GameLamp {

	enum class EventType : uint8_t
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
	};

	enum EventCategory : uint8_t
	{
		// Maybe bit fields can be used
		None = 0, // Maybe should be removed or increment BIT for fields.
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4),
	};

#define EVENT_CLASS_TYPE(type)		static EventType getStaticType() { return EventType::type; }\
									virtual EventType getEventType() const override { return getStaticType(); }\
									virtual std::string getName() const override { return #type;  }

#define EVENT_CLASS_CATEGORY(category)		virtual uint8_t getCategoryFlags() const override { return category; }

	class GL_API Event
	{
		friend class EventDispatcher;
	public:
		virtual ~Event() = default;

		virtual EventType getEventType() const = 0;
		virtual std::string getName() const = 0;
		virtual uint8_t getCategoryFlags() const = 0;
//#ifdef GL_DEBUG
		virtual std::string getDebugInfo() const { return getName(); }
//#endif

		bool isInCategory(EventCategory category)
		{
			return getCategoryFlags() & category;
		}

	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event{event}
		{}

		template<typename T, typename F>
		bool dispatch(const F& func)
		{
			// Maybe should be removed not in Debug mode
			if (!IS_BASE_OF<Event, T>())
			{
				// TODO: Drop an assert
			}

			if (m_Event.getEventType() == T::GetStaticType())
			{
				m_Event.m_Handled |= func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.getDebugInfo();
	}
}
