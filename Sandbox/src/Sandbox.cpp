#include <GameLamp.h>

#include <memory>

#include <imgui.h>

class ExampleLayer : public GameLamp::Layer
{
public:
	ExampleLayer()
		: Layer("Sandbox")
	{
	}

	void onImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void onUpdate() override
	{
		//GL_CLIENT_INFO("ExampleLayer1::onUpdate");
		if (GameLamp::Input::isKeyPressed(GameLamp::Key::Tab)) {
			GL_CLIENT_INFO("Tab is pressed");
		}
	}

	void onEvent(GameLamp::Event& e) override
	{
		//GL_CLIENT_INFO("ExampleLayer1::onEvent: {0}", e);
		GameLamp::EventDispatcher dispatcher(e);

		dispatcher.dispatch<GameLamp::MouseButtonReleasedEvent>([](GameLamp::MouseButtonReleasedEvent& event) -> bool
			{
				GL_CLIENT_INFO(event);
				return true;
			}
		);

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
