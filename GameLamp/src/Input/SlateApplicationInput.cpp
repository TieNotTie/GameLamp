#include "SlateApplicationInput.h"

#include "Core/Log.h"
#include "Input/IEventHandler.h"

namespace Lamp
{

	std::shared_ptr<SlateApplicationInputHandler> SlateApplicationInputHandler::Get(uint32_t)
	{
		/*
		 * Temporary solution, until multiple windows can be handled
		 */
		static SlateApplicationInputHandler* rawPtr = new SlateApplicationInputHandler();
		static auto SlateInputHandler = std::shared_ptr<SlateApplicationInputHandler>(rawPtr);

		return SlateInputHandler;
	}

	SlateApplicationInputHandler::SlateApplicationInputHandler()
		:m_LastMousePosition{}
	{ }

	void SlateApplicationInputHandler::addCoreKeyEventHandler(std::shared_ptr<IKeyEventHandler> keyEventHandler)
	{
		m_CoreKeyEventHandlers.push_back(keyEventHandler);
	}

	void SlateApplicationInputHandler::addCoreMouseEventHandler(std::shared_ptr<class IMouseEventHandler> keyEventHandler)
	{
		m_CoreMouseEventHandlers.push_back(keyEventHandler);
	}

	void SlateApplicationInputHandler::cacheKeyState(const Key key, ButtonStates state)
	{
		if (state == ButtonStates::Invalid) GL_CORE_WARN("Received 'Invalid' state for Key: {}", key.getName());
		if (key.isModifierKey()) updateModifiers(key, state);

		// if state is 'invalid' or 'released'(key is up) -> save 'released' state; if state is 'pressed' or 'hiold' -> save 'pressed' state
		state = (state == ButtonStates::Invalid || state == ButtonStates::Released) ? ButtonStates::Released : ButtonStates::Pressed;

		m_KeyStatesCached[key] = state;
	}

	const ModifierKeysState SlateApplicationInputHandler::getModifiersState() const
	{
		return ModifierKeysState(	m_ModifierKeysState.IsLeftShiftDown,
									m_ModifierKeysState.IsRightShiftDown,
									m_ModifierKeysState.IsLeftControlDown,
									m_ModifierKeysState.IsRightControlDown,
									m_ModifierKeysState.IsLeftAltDown,
									m_ModifierKeysState.IsRightAltDown,
									m_ModifierKeysState.IsLeftCommandDown,
									m_ModifierKeysState.IsRightCommandDown,
									m_ModifierKeysState.IsCapsLocked,
									m_ModifierKeysState.IsNumLocked);
	}
	//uint16_t m_IsNumLocked : 1;
	void SlateApplicationInputHandler::updateModifiers(const Key key, const ButtonStates state)
	{
		// does not modify is 'ButtonStates::Hold' because 'ButtonStates::Pressed' was already processed and no need to repeat all actions again
		if (state == ButtonStates::Hold || state == ButtonStates::Invalid) return;
		const bool keyIsPressed = (state == ButtonStates::Pressed);

		if (EKeys::LeftShift == key) m_ModifierKeysState.IsLeftShiftDown = keyIsPressed;
		else if (EKeys::RightShift == key) m_ModifierKeysState.IsRightShiftDown = keyIsPressed;
		else if (EKeys::LeftCommand == key) m_ModifierKeysState.IsLeftCommandDown = keyIsPressed;
		else if (EKeys::RightCommand == key) m_ModifierKeysState.IsRightCommandDown = keyIsPressed;
		else if (EKeys::LeftControl == key) m_ModifierKeysState.IsLeftControlDown = keyIsPressed;
		else if (EKeys::RightControl == key) m_ModifierKeysState.IsRightControlDown = keyIsPressed;
		else if (EKeys::LeftAlt == key) m_ModifierKeysState.IsLeftAltDown = keyIsPressed;
		else if (EKeys::RightAlt == key) m_ModifierKeysState.IsRightAltDown = keyIsPressed;
		else if (EKeys::CapsLock == key) m_ModifierKeysState.IsCapsLocked = keyIsPressed;
		else if (EKeys::NumLock == key) m_ModifierKeysState.IsNumLocked = keyIsPressed;
	}

	void SlateApplicationInputHandler::addUserKeyEventHandler(std::shared_ptr<class IKeyEventHandler> keyEventHandler)
	{
		m_UserKeyEventHandlers.push_back(keyEventHandler);
	}

	void SlateApplicationInputHandler::addUserMouseEventHandler(std::shared_ptr<class IMouseEventHandler> keyEventHandler)
	{
		m_UserMouseEventHandlers.push_back(keyEventHandler);
	}

	void SlateApplicationInputHandler::onKeyEvent(Key key, ButtonStates state)
	{
		cacheKeyState(key, state);
		const auto modState = getModifiersState();
		KeyEvent e(key, modState, state == ButtonStates::Hold);

		switch (state)
		{
		case ButtonStates::Pressed: {
			for (auto i : m_CoreKeyEventHandlers)
			{
				i->onKeyPressed(e);
			}

			for (auto i : m_UserKeyEventHandlers)
			{
				i->onKeyPressed(e);
			}
			return;
		}
		case ButtonStates::Released: {
			for (auto i : m_CoreKeyEventHandlers)
			{
				i->onKeyReleased(e);
			}

			for (auto i : m_UserKeyEventHandlers)
			{
				i->onKeyReleased(e);
			}
			return;
		}
		case ButtonStates::Hold: {
			for (auto i : m_CoreKeyEventHandlers)
			{
				i->onKeyHold(e);
			}

			for (auto i : m_UserKeyEventHandlers)
			{
				i->onKeyHold(e);
			}
			return;
		}
		case ButtonStates::Invalid:
			GL_CORE_ERROR("Invalid Button state is received; Key: {}", key.getName())
		};
	}

	void SlateApplicationInputHandler::onMouseButtonEvent(Key key, ButtonStates state)
	{
		cacheKeyState(key, state);
		const auto modState = getModifiersState();
		Position2D mouseCursorPosition{0, 0};
		MouseButtonEvent e(key, modState, state == ButtonStates::Hold, mouseCursorPosition);

		switch (state)
		{
		case ButtonStates::Pressed: {
			for (auto i : m_CoreMouseEventHandlers)
			{
				i->onMouseButtonPressed(e);
			}

			for (auto i : m_UserMouseEventHandlers)
			{
				i->onMouseButtonPressed(e);
			}

			return;
		}
		case ButtonStates::Released: {
			for (auto i : m_CoreMouseEventHandlers)
			{
				i->onMouseButtonReleased(e);
			}

			for (auto i : m_UserMouseEventHandlers)
			{
				i->onMouseButtonReleased(e);
			}

			return;
		}
		case ButtonStates::Hold: {
			for (auto i : m_CoreMouseEventHandlers)
			{
				i->onMouseButtonHold(e);
			}

			for (auto i : m_UserMouseEventHandlers)
			{
				i->onMouseButtonHold(e);
			}
			return;
		}

		}
	}

	void SlateApplicationInputHandler::onMouseMoved(Position2D mousePosition)
	{
		Position2D mouseMovementDelta = mousePosition - m_LastMousePosition;
		m_LastMousePosition = mousePosition;
		const auto modState = getModifiersState();
		for (auto i : m_CoreMouseEventHandlers)
		{
			i->onMouseMoved(mousePosition, mouseMovementDelta, modState);
		}

		for (auto i : m_UserMouseEventHandlers)
		{
			i->onMouseMoved(mousePosition, mouseMovementDelta, modState);
		}
	}

	void SlateApplicationInputHandler::onMouseWheelScrolledEvent(double offset)
	{
		const auto modState = getModifiersState();
		for (auto i : m_CoreMouseEventHandlers)
		{
			i->onMouseWheelScrolled(offset, modState);
		}

		for (auto i : m_UserMouseEventHandlers)
		{
			i->onMouseWheelScrolled(offset, modState);
		}
	}

	bool SlateApplicationInputHandler::isKeyPressed(const Key& key) const
	{
		const auto it = m_KeyStatesCached.find(key);
		if (it != m_KeyStatesCached.end()) return it->second == ButtonStates::Pressed;
		else return false;
	}

	Position2D SlateApplicationInputHandler::getMousePosition() const
	{
		return m_LastMousePosition;
	}

	void SlateApplicationInputHandler::setMousePosition(Position2D newPos)
	{

	}

}
