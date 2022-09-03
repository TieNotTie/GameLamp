#pragma once

#include "Application.h"
#include "Log.h"

#ifdef GL_PLATFORM_WINDOWS

extern GameLamp::Application* GameLamp::CreateApplication();

int main()
{
	GameLamp::Log::init();
	GL_CORE_INFO("Log inited!");
	
	auto app = GameLamp::CreateApplication();
	
	app->run();
	delete app;
	return 0;
}

#endif  // GL_PLATFORM_WINDOWS
