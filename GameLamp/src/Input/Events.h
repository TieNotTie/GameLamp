#pragma once

#include "Input/InputCoreTypes.h"
#include "Util/Position.h"

namespace Lamp {
	
	class InputEvent
	{
	protected:
		InputEvent()
			: m_ModifierKeys{ ModifierKeysState() },
			m_IsRepeat{false}
		{
		}
		// isRepeat - may be redundant
		InputEvent(const ModifierKeysState& modifierKeys, bool isRepeat)
			: m_ModifierKeys{modifierKeys}, m_IsRepeat{isRepeat}
		{
		}

	public:
		bool isRepeat() const 
		{
			return m_IsRepeat;
		}

		bool isAnyShiftDown() const
		{
			return m_ModifierKeys.isAnyShiftDown();
		}

		bool isLeftShifDown() const
		{
			return m_ModifierKeys.isLeftShifDown();
		}

		bool isRightShiftDown() const
		{
			return m_ModifierKeys.isRightShiftDown();
		}

		bool isAnyControlDown() const
		{
			return m_ModifierKeys.isAnyControlDown();
		}

		bool isLeftControlDown() const
		{
			return m_ModifierKeys.isLeftControlDown();
		}

		bool isRightControlDown() const
		{
			return m_ModifierKeys.isRightControlDown();
		}

		bool isAnyAltDown() const
		{
			return m_ModifierKeys.isAnyAltDown();
		}

		bool isLeftAltDown() const
		{
			return m_ModifierKeys.isLeftAltDown();
		}

		bool isRightAltDown() const
		{
			return m_ModifierKeys.isRightAltDown();
		}

		/*
		 * Mac-specific key. On windows platform, the 'win' key
		*/
		bool isAnyCommandDown() const
		{
			return m_ModifierKeys.isAnyCommandDown();
		}

		bool isLeftCommandDown() const
		{
			return m_ModifierKeys.isLeftCommandDown();
		}

		bool isRightCommandDown() const
		{
			return m_ModifierKeys.isRightCommandDown();
		}

		bool isCapsLocked() const
		{
			return m_ModifierKeys.isCapsLocked();
		}

	protected:

		ModifierKeysState m_ModifierKeys;
		bool m_IsRepeat;
	};

	class KeyEvent : public InputEvent
	{
	public:
		KeyEvent(const Key key, const ModifierKeysState& modifierKeys, bool isRepeat, uint32_t keyCode = 0)
			: InputEvent(modifierKeys, isRepeat), m_Key{key}, m_KeyCode{keyCode}
		{}

		inline const Key getKey() const { return m_Key; }
		inline uint32_t getKeyCode() const { return m_KeyCode; }

	private:
		const Key m_Key;

		const uint32_t m_KeyCode;
	};

	class MouseButtonEvent : public InputEvent
	{
	public:
		MouseButtonEvent(const Key key, const ModifierKeysState& modifierKeys, bool isRepeat, const Position2D& currentMousePosition)
			: InputEvent(modifierKeys, isRepeat), m_Key{key}, m_Position{currentMousePosition}
		{ }

		inline const Key& getKey() const { return m_Key; }
		inline const Position2D& getCurrentMousePosition() const { return m_Position; }

	private: 
		const Key m_Key;
		const Position2D m_Position;
	};

}
