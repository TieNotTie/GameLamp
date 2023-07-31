#pragma once

#include <GameLamp.h>

#include <imgui.h>

class SandboxLayer : public GameLamp::Layer 
{
public:
	SandboxLayer();
	void onAttach() override;
	void onDetach() override;

	void onImGuiRender() override;
	void onUpdate(GameLamp::Timestep ts) override;

	void onEvent(GameLamp::Event& e) override {}

private:
	std::shared_ptr<GameLamp::OrthographicCamera> m_OrtoCamera;

	std::shared_ptr<GameLamp::Shader> m_Shader;
	std::shared_ptr<GameLamp::VertexArray> m_VertexArray;

	std::shared_ptr<GameLamp::Shader> m_ShaderSquare;
	std::shared_ptr<GameLamp::VertexArray> m_SquareVA;

private:
	bool m_ShowDemoWindow = true;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;
	float m_CameraMoveSpeed = 5.0f;
	glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };

	glm::vec4 m_ThemeColors = { 0.2f, 0.3f, 0.8f, 1.0f };
	glm::vec3 m_SquarePosition = { 0.0f, 0.0f, 0.0f };
	float m_SquareMoveSpeed = 1.0f;
};
