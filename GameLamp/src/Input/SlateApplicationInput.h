#pragma once

#include "Input/InputCoreTypes.h"
#include "Util/Position.h"

#include <list>
#include <memory>
#include <map>

namespace Lamp
{
	class SlateApplicationInputHandler
	{
	public:
		static std::shared_ptr<SlateApplicationInputHandler> Get(uint32_t WindowId = 0);

		void addUserKeyEventHandler(std::shared_ptr<class IKeyEventHandler> keyEventHandler);
		void addUserMouseEventHandler(std::shared_ptr<class IMouseEventHandler> keyEventHandler);

	public:
		void onKeyEvent(const Key key, const ButtonStates action);
		void onMouseButtonEvent(const Key key, const ButtonStates action);
		void onMouseMoved(const Position2D mousePosition);
		void onMouseWheelScrolledEvent(const double offset);

	public:
		bool isKeyPressed(const Key&) const;
		Position2D getMousePosition() const;
		void setMousePosition(Position2D newPos);

	private:
		/*
		 * Make a restriction that only the Application class can add 'core' type input handlers
		 * so user application class cannot use this methods. As core modules has higher priority then
		 * user modules
		 */
		friend class Application;
		// Add subscribing core and user input event handlers
		void addCoreKeyEventHandler(std::shared_ptr<class IKeyEventHandler> keyEventHandler);
		void addCoreMouseEventHandler(std::shared_ptr<class IMouseEventHandler> keyEventHandler);

	private:
		// Save a state of given key (Pressed, Released, Hold)
		void cacheKeyState(const Key key, ButtonStates state);
		const ModifierKeysState getModifiersState() const;
		void updateModifiers(const Key key, const ButtonStates state);
	
	private:
		SlateApplicationInputHandler();
	private: 
		std::list<std::shared_ptr<class IKeyEventHandler>> m_CoreKeyEventHandlers;
		std::list<std::shared_ptr<class IKeyEventHandler>> m_UserKeyEventHandlers;
		std::list<std::shared_ptr<class IMouseEventHandler>> m_CoreMouseEventHandlers;
		std::list<std::shared_ptr<class IMouseEventHandler>> m_UserMouseEventHandlers;

		std::map<const Key, ButtonStates> m_KeyStatesCached;

		Position2D m_LastMousePosition;
		
		// A copy of ModifiersKeyState - as ModifiersKeyState values cannot be changed
		struct
		{
			bool IsLeftShiftDown = false;
			bool IsRightShiftDown = false;
			bool IsLeftControlDown = false;
			bool IsRightControlDown = false;
			bool IsLeftAltDown = false;
			bool IsRightAltDown = false;
			bool IsLeftCommandDown = false;
			bool IsRightCommandDown = false;
			bool IsCapsLocked = false;
			bool IsNumLocked = false;
		} m_ModifierKeysState;

	private:
		/*
		 * For now this is redundant as engine handles only 1 window.
		 * In the future is window ID can be assigned to different windows, so SlateApplicationInputEventHandler
		 * can separate inputs from multiple windows
		 */
		// static std::map<WindowId, std::shared_ptr<SlateApplicationInputEventHandler>> m_WindowToHandler;
	};

}
