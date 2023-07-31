#include <GameLamp.h>

#include "GameLamp/Core/EntryPoint.h"

#include "SandboxLayer.h"

class Sandbox : public GameLamp::Application 
{
public:
	Sandbox(GameLamp::ApplicationSpecification spec)
		: GameLamp::Application(spec)
	{
		pushLayer(new SandboxLayer());
	}

	~Sandbox()
	{}
};

GameLamp::Application* GameLamp::CreateApplication(){
	GameLamp::ApplicationSpecification spec("Sandbox", 1080, 720);
	return new Sandbox(spec);
}
