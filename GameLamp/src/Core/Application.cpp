#include "Application.h"

#if GL_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

#include "Core/CoreInitializer.h"
#include "Core/Log.h"
#include "Input/IEventHandler.h"
#include "Input/InputCoreTypes.h"
#include "Input/PlatformInputEventHandler.h"
#include "Input/SlateApplicationInput.h"
#include "Util/Time.h"

namespace Lamp {

	bool Application::m_IsRunning = false;

	Application::Application(int argc, char** argv)
	{
		initInternal(argc, argv);
	}

	Application::~Application()
	{
		shutdown();
		shutdownInternal();
	}

	/* TODO: !!! Research whether it is worth to move all modules and theirs initialization to separate static class 
	 *
	 **/

	int Application::run(int argc, char** argv)
	{
		static bool IsAlreadyRunning = false;
		GL_CORE_ASSERT(!IsAlreadyRunning && "Application is already running! Application::run should be called ONLY from entry point function")
		double delta = .0f;

		IsAlreadyRunning = true;
		// Main Game loop
		while (m_IsRunning)
		{
			UpdateDeltaTime();
			delta = GetDeltaTime();

			tickInternal(delta);
			tick(delta); // Call a tick for User application
		}
		IsAlreadyRunning = false;
		return 0;
	}

	void Application::initInternal(int argc, char** argv)
	{
		m_Window = Window::create();
		
		CoreInitializer::InitCoreModules();

		m_IsRunning = true;
	}

	void Application::shutdownInternal()
	{
		GL_CORE_INFO("Application::Shutdown");
		m_Window->closeWindow();
		delete m_Window;
		m_Window = nullptr;
	}

	void Application::addCoreInputKeyEventHandler(std::shared_ptr<class IKeyEventHandler> coreKeyEventHandler)
	{
		SlateApplicationInputHandler::Get()->addCoreKeyEventHandler(coreKeyEventHandler);
	}

	void Application::addUserInputKeyEventHandler(std::shared_ptr<class IKeyEventHandler> userKeyEventHandler)
	{
		SlateApplicationInputHandler::Get()->addUserKeyEventHandler(userKeyEventHandler);
	}	
	
	void Application::addCoreInputMouseEventHandler(std::shared_ptr<class IMouseEventHandler> coreMouseEventHandler)
	{
		SlateApplicationInputHandler::Get()->addCoreMouseEventHandler(coreMouseEventHandler);
	}

	void Application::addUserInputMouseEventHandler(std::shared_ptr<class IMouseEventHandler> userMouseEventHandler)
	{
		SlateApplicationInputHandler::Get()->addUserMouseEventHandler(userMouseEventHandler);
	}

	bool Application::isKeyPressed(const Key& key)
	{
		return SlateApplicationInputHandler::Get()->isKeyPressed(key);
	}

	Position2D Application::getMousePosition()
	{
		return SlateApplicationInputHandler::Get()->getMousePosition();
	}

	double Application::getCurrentDelta() const
	{
		return GetDeltaTime();
	}

	void Application::tickInternal(double delta)
	{
		bool show_demo_window = true;

		// TODO: Add OpenGL update
		m_Window->tick(delta);

	}
}
