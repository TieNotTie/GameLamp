#pragma once

namespace Lamp {

	class Window;

	class Application
	{
	public:
		Application();

		int run(int argc = 0, char** argv = nullptr);

		virtual void init(int arhc, char** argv) {}
		virtual void tick(double delta = 0.0) {}
		virtual void shutdown() {}

	private:

		void tickInternal(double delta);

	private:
		Window* m_Window = nullptr;
	};

}
