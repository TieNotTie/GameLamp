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
		virtual void onImGuiRender() override;

		void begin();
		void end();
	private:
		float m_Time = 0.0f;
	};

} // namespace GameLamp
