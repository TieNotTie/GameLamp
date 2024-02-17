#pragma once 
#include "Core/Application.h"
#include "Core/Core.h"
#include "Core/Log.h"

#if GL_PLATFORM_WINDOWS
#include <Windows.h>
#endif

extern Lamp::Application* CreateApplication(int argc, char** argv);

#if GL_PLATFORM_WINDOWS
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPreInst, LPSTR lpCmdLine, int nCmdShow)
{
	Lamp::Application* app = CreateApplication(__argc, __argv);

	MessageBox(NULL, L"hello, world", L"SandBox", 0);
	
	return app->run(__argc, __argv);
}

#else

// Entry point of the game. Include this file to the main.cpp of game project.
int main(int argc, char** argv)
{
	Lamp::Logger::Init();
	GL_CORE_INFO("GameLamp is running");

	int result = Lamp::CoreInit();

	if (result) return result;

	Lamp::Application* app = CreateApplication(argc, argv);

	return app->run(argc, argv);
}

#endif
