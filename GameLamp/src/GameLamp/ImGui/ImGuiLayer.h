#pragma once

#include "GameLamp/Core/Core.h"
#include "GameLamp/Core/Layer.h"
#include "GameLamp/Event/ApplicationEvent.h"
#include "GameLamp/Event/MouseEvent.h"
#include "GameLamp/Event/KeyEvent.h"

namespace GameLamp {

	class GL_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void onAttach() override;
		virtual void onDetach() override;
		virtual void onUpdate() override;
		virtual void onEvent(Event& e) override;

	private:
		bool onMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool onMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool onMouseMovedEvent(MouseMovedEvent& e);
		bool onMouseScrolledEvent(MouseScrolledEvent& e);
		bool onKeyPressedEvent(KeyPressedEvent& e);
		bool onKeyReleasedEvent(KeyReleasedEvent& e);
		bool onKeyTypedEvent(KeyTypedEvent& e);
		bool onWindowResizedEvent(WindowResizeEvent& e);


	private:
		float m_Time = 0.0f;
	};

} // namespace GameLamp
