#pragma once 
#include "Core/Application.h"
#include "Core/Core.h"


extern Lamp::Application* CreateApplication(int argc, char** argv);


// Entry point of the game. Include this file to the main.cpp of game project.
int main(int argc, char** argv)
{
	int result = Lamp::CoreInit();

	if (result) return result;

	Lamp::Application* app = CreateApplication(argc, argv);

	return app->run(argc, argv);
}

