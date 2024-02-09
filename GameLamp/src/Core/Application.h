#pragma once

namespace Lamp {

	class Window;

	class Application
	{
	public:
		Application();

		int run(int argc = 0, char** argv = nullptr);

		virtual void init(int arhc, char** argv) {}
		virtual void tick(float delta = 0.0f) {}
		virtual void shutdown() {}

	private:
		Window* m_Window = nullptr;
	};

}
