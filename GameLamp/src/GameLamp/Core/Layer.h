#pragma once

#include "GameLamp/Core/Core.h"
#include "GameLamp/Core/Timestep.h"
#include "GameLamp/Event/Event.h"

namespace GameLamp {

	class GL_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate(Timestep ts) {}
		virtual void onImGuiRender() {}
		virtual void onEvent(Event& e)  {}

		inline const std::string& getName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};

} // namespace GameLamp
