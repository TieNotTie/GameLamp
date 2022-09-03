#pragma once

#include "Event.h"
#include "GameLamp/Core/KeyCode.h"

namespace GameLamp {

	class GL_API KeyEvent : public Event
	{
	public:
		KeyCode getKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);

	protected:
		KeyEvent(KeyCode code)
			: m_KeyCode{code}
		{}
	
		KeyCode m_KeyCode;
	};

	class GL_API KeyPressedEvent final : public KeyEvent
	{
	public:
		KeyPressedEvent(const KeyCode code, const uint16_t repeatCount)
			: KeyEvent{code}, m_RepeatCount{repeatCount}
		{}

		uint16_t getRepeatCount() const { return m_RepeatCount; }

		virtual std::string getDebugInfo() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << static_cast<uint16_t>(m_KeyCode) << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		uint16_t m_RepeatCount;
	};

	class GL_API KeyReleasedEvent final : public KeyEvent
	{
		KeyReleasedEvent(KeyCode code)
			: KeyEvent{code}
		{}

		virtual std::string getDebugInfo() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << static_cast<uint16_t>(m_KeyCode);
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}
