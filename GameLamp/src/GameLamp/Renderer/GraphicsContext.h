#pragma once

namespace GameLamp {

	class GraphicsContext
	{
	public: 
		virtual void init() = 0;
		virtual void swapBuffers() = 0;
	};

};
