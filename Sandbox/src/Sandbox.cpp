#include <GameLamp.h>

#include <memory>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi

class ExampleLayer : public GameLamp::Layer
{
public:
	ExampleLayer()
		: Layer("Sandbox")
	{
		auto cam = camera(5.0f, {0.5f, 0.5f });
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
		pushOverlay(new GameLamp::ImGuiLayer());
	}

	~Sandbox()
	{}

};

GameLamp::Application* GameLamp::CreateApplication(){
	return new Sandbox();
}
