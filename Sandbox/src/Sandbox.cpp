#include <GameLamp.h>

#include <memory>

class ExampleLayer : public GameLamp::Layer
{
public:
	ExampleLayer()
		: Layer("Sandbox")
	{}

	void onUpdate() override
	{
		//GL_CLIENT_INFO("ExampleLayer1::onUpdate");
	}

	void onEvent(GameLamp::Event& e) override
	{
		GL_CLIENT_INFO("ExampleLayer1::onEvent: {0}", e);
	}
};

class Sandbox : public GameLamp::Application 
{
public:
	Sandbox()
	{
		pushLayer(new ExampleLayer());
	}

	~Sandbox()
	{}

};

GameLamp::Application* GameLamp::CreateApplication(){
	return new Sandbox();
}
