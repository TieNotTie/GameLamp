#pragma once

#include "Core/Log.h"
//#include "Input/IEventHandler.h"

#include <memory>

namespace Lamp {

	class Application
	{
	public:
		Application(int argc, char** argv);
		~Application();

		// To be redefined in user application 
		/* Init - 
		 *
		 */
		virtual void init(int argc, char** argv) {}
		virtual void tick(double delta) {}
		virtual void shutdown() {}

	public:
		// Input managing -- ?? Maybe worth to be moved to a separate global class
		// 'addCore*' are not expected to be used by user application modules
		static void addCoreInputKeyEventHandler(std::shared_ptr<class IKeyEventHandler>);
		static void addCoreInputMouseEventHandler(std::shared_ptr<class IMouseEventHandler>);
		//void addCoreEventHandler(std::shared_ptr<class IMouseEventHandler>);

		static void addUserInputKeyEventHandler(std::shared_ptr<class IKeyEventHandler>);
		static void addUserInputMouseEventHandler(std::shared_ptr<class IMouseEventHandler>);
		// TODO: ??? Add a possibility to add handlers in such format:
		// void AddHandler(KeyPressEvent, std::function<>)
		
		static bool isKeyPressed(const class Key& key);
		static struct Position2D getMousePosition();

	public:
		// Get a time spent for a one tick(frame)
		double getCurrentDelta() const;

	public:
		// Is called from entry point
		int run(int argc = 0, char** argv = nullptr);
	
	private:
		void tickInternal(double delta);
		void initInternal(int argc, char** argv);
		void shutdownInternal();

	private:
		class Window* m_Window = nullptr;
	private:
		static bool m_IsRunning;
	};

}
