#pragma once

#include "Input/Events.h"
#include "Input/InputCoreTypes.h"
#include "Util/Position.h"

namespace Lamp {


	class IKeyEventHandler 
	{
	public:
		virtual ~IKeyEventHandler() = default;
		virtual void onKeyPressed(const KeyEvent&) = 0;
		virtual void onKeyReleased(const KeyEvent&) = 0;
		virtual void onKeyHold(const KeyEvent&) = 0;
	};

	class IMouseEventHandler
	{
	public:
		virtual ~IMouseEventHandler() = default;
		virtual void onMouseButtonPressed(const MouseButtonEvent&) = 0;
		virtual void onMouseButtonReleased(const MouseButtonEvent&) = 0;
		virtual void onMouseButtonHold(const MouseButtonEvent&) = 0;

		virtual void onMouseWheelScrolled(double offset, const ModifierKeysState& modifierKeys) = 0;
	
		virtual void onMouseMoved(const Position2D& currentPosition, const Position2D& deltaMouseMovement, const ModifierKeysState& modifierKeys) = 0;
	};

	class IWindowEventHandler
	{
	public:

	};

}
