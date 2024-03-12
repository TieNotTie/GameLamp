#pragma once

#include "Input/SlateApplicationInput.h"

#include <memory>

namespace Lamp {
	
	class PlatformInputEventHandler
	{
	public:
		// Keyboard events
		virtual void onKeyEvent(int key, int action, int mods) = 0;
		
		// Mouse events
		virtual void onMouseButtonEvent(int button, int action, int mods) = 0;
		virtual void onMouseMovedEvent(double x, double y) = 0;
		virtual void onMouseWheelScrolledEvent(double xOffset) = 0;
		
		// Window events
		//virtual void onWindowResize() = 0;
		//virtual void onWindowClose() = 0;

		static std::shared_ptr<PlatformInputEventHandler> GetPlatfromEventHandler();
	protected: 
		PlatformInputEventHandler()
			: m_SlateInputEventHandler(SlateApplicationInputHandler::Get())
		{}
	protected:
		std::shared_ptr<class SlateApplicationInputHandler> m_SlateInputEventHandler;
	};
}
