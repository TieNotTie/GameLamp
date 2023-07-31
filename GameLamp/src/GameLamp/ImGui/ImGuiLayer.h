#pragma once

#include "GameLamp/Core/Core.h"
#include "GameLamp/Core/Layer.h"
#include "GameLamp/Event/ApplicationEvent.h"
#include "GameLamp/Event/MouseEvent.h"
#include "GameLamp/Event/KeyEvent.h"

//#include <glm/glm.hpp>

namespace GameLamp {

	struct Color { float r, g, b, a; };

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

		//glm::vec4 getColor() const { return m_Color; }
		
	private:
		void drawFpsCounter();

	private:
		float m_Time = 0.0f;
		//glm::vec4 m_Color = { 0.0f, 0.0f, 0.0f, 0.0f };
	};

} // namespace GameLamp
