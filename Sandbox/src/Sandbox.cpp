#include <GameLamp.h>

#include <memory>

class Sandbox : public GameLamp::Application 
{
public:
	Sandbox()
	{}

	~Sandbox()
	{}

};

GameLamp::Application* GameLamp::CreateApplication(){
	return new Sandbox();
}
