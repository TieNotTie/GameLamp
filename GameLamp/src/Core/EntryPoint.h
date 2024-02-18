#pragma once 
#include "Core/Application.h"
#include "Core/Core.h"
#include "Core/Log.h"

#if GL_PLATFORM_WINDOWS
#include <Windows.h>
#endif

#include <future>

extern Lamp::Application* CreateApplication(int argc, char** argv);

#if GL_PLATFORM_WINDOWS
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPreInst, LPSTR lpCmdLine, int nCmdShow)
{
	Lamp::Application* app = CreateApplication(__argc, __argv);

	return app->run(__argc, __argv);
}

#else

// Entry point of the game. Include this file to the main.cpp of game project.
int main(int argc, char** argv)
{
	Lamp::Application* app = CreateApplication(argc, argv);

	return app->run(argc, argv);
}

#endif
