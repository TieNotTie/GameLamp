#include "SandboxLayer.h"

#include "GameLamp/Renderer/Renderer.h"
#include "GameLamp/Platform/OpenGL/OpenGLShader.h"

#include <glm/gtc/type_ptr.hpp>

using namespace GameLamp;

SandboxLayer::SandboxLayer()
	: m_OrtoCamera{ std::make_shared<OrthographicCamera>(-1.0f, 1.0f, -1.0f, 1.0f) }
{
}

void SandboxLayer::onAttach()
{
	m_VertexArray.reset(VertexArray::create());

	float vertices[3 * 7] = {
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
		0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.5f, 0.0f,  1.0f, 1.0f, 0.0f, 1.0f,
	};

	std::shared_ptr<VertexBuffer> vertexBuffer;
	vertexBuffer.reset(VertexBuffer::create(vertices, sizeof(vertices)));

	vertexBuffer->setLayout({
		{ ShaderDataType::Float3, "a_Position"},
		{ ShaderDataType::Float4, "a_Color"},
		});

	m_VertexArray->addVertexBuffer(vertexBuffer);

	unsigned int indices[3] = { 0, 1, 2 };
	std::shared_ptr<IndexBuffer> indexBuffer;
	indexBuffer.reset(IndexBuffer::create(indices, sizeof(indices) / sizeof(unsigned int)));
	m_VertexArray->setIndexBuffer(indexBuffer);


	std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Color = a_Color;
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}	

		)";

	std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 outputColor;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				outputColor = vec4(v_Position * 0.5 + 0.5, 1.0) * v_Color;
			}
		)";
	m_Shader.reset(Shader::create(vertexSrc, fragmentSrc));


	m_SquareVA.reset(VertexArray::create());

	float verticesSquare[3 * 4] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	std::shared_ptr<VertexBuffer> squareVB;
	squareVB.reset(VertexBuffer::create(verticesSquare, sizeof(verticesSquare)));

	squareVB->setLayout({
		{ ShaderDataType::Float3, "a_Position"},
		});

	m_SquareVA->addVertexBuffer(squareVB);

	unsigned int squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
	std::shared_ptr<IndexBuffer> squareIB;
	squareIB.reset(IndexBuffer::create(squareIndices, sizeof(squareIndices) / sizeof(unsigned int)));
	m_SquareVA->setIndexBuffer(squareIB);

	std::string vertexSrcSquare = R"(
			#version 330 core

			layout(location=0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}	

		)";

	std::string fragmentSrcSquare = R"(
			#version 330 core

			layout(location = 0) out vec4 outputColor;

			in vec3 v_Position;
			uniform vec4 u_Color;

			void main()
			{
				outputColor = vec4(v_Position * 0.5 + 0.5, 1.0) * u_Color;
			}
		
		)";

	m_ShaderSquare.reset(Shader::create(vertexSrcSquare, fragmentSrcSquare));

}

void SandboxLayer::onDetach()
{
}

void SandboxLayer::onImGuiRender()
{
	ImGui::ShowDemoWindow(&m_ShowDemoWindow);

	ImGui::Begin("Camera");
	{
		ImGui::SliderFloat("Rotation Angle", &m_CameraRotation, 0.0f, 360.0f, "Angle = %.3f");
		ImGui::SliderFloat("Rotation Speed", &m_CameraRotationSpeed, 0.0f, 360.0f, "Speed = %.3f");
		ImGui::SeparatorText("Camera position");
		ImGui::SliderFloat("Move speed", &m_CameraMoveSpeed, 0.0f, 10.0f, "Speed = %.3f");
		ImGui::InputFloat3("CameraPositiion", glm::value_ptr(m_CameraPosition));
		ImGui::SliderFloat("Rectangle move speed", &m_SquareMoveSpeed, 0.0f, 10.0f, "Speed = %.3f");
	}
	ImGui::End();

	ImGui::Begin("Color");
	{
		ImGui::ColorEdit4("Theme color", glm::value_ptr(m_ThemeColors), ImGuiColorEditFlags_DisplayRGB | ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_Float);
	}
	ImGui::End();
}

void SandboxLayer::onUpdate(Timestep ts)
{
	//GL_CORE_INFO("Timestep: {0}s {1}ms", ts.getSeconds(), ts.getMilliseconds());

	if (m_CameraRotation > 360) m_CameraRotation -= 360;
	else if (m_CameraRotation < 0) m_CameraRotation += 360;

	if (Input::isKeyPressed(Key::D))
		m_CameraPosition.x += m_CameraMoveSpeed * ts;
	else if (Input::isKeyPressed(Key::A))
		m_CameraPosition.x -= m_CameraMoveSpeed * ts;
	
	if (Input::isKeyPressed(Key::S))
		m_CameraPosition.y -= m_CameraMoveSpeed * ts;
	else if (Input::isKeyPressed(Key::W))
		m_CameraPosition.y += m_CameraMoveSpeed * ts;

	if (Input::isKeyPressed(Key::Q))
		m_CameraRotation -= m_CameraRotationSpeed * ts;	
	else if (Input::isKeyPressed(Key::E))
		m_CameraRotation += m_CameraRotationSpeed * ts;

	// Rectangle movement
	if (Input::isKeyPressed(Key::Right))
		m_SquarePosition.x += m_SquareMoveSpeed * ts;
	else if (Input::isKeyPressed(Key::Left))
		m_SquarePosition.x -= m_SquareMoveSpeed * ts;

	if (Input::isKeyPressed(Key::Down))
		m_SquarePosition.y -= m_SquareMoveSpeed * ts;
	else if (Input::isKeyPressed(Key::Up))
		m_SquarePosition.y += m_SquareMoveSpeed * ts;


	RenderCommand::setClearColor({ 0.3f, 0.3f, 0.3f, 0.0f });
	RenderCommand::clear();

	m_OrtoCamera->setPosition(m_CameraPosition);
	m_OrtoCamera->setRotation(m_CameraRotation);

	Renderer::beginScene(m_OrtoCamera);
	{		
		static glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
		for (int y = 0; y < 20; ++y)
			for (int x = 0; x < 20; ++x) {
				glm::vec3 pos(x * 0.11f, y * 0.11, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos + m_SquarePosition) * scale;
				std::dynamic_pointer_cast<OpenGLShader>(m_ShaderSquare)->uploadUniform("u_Color", m_ThemeColors);
				std::dynamic_pointer_cast<OpenGLShader>(m_ShaderSquare)->uploadUniform("u_Color", m_ThemeColors * (glm::sin(pos.x + Time::getSystemTime()) * glm::sin(pos.y + Time::getSystemTime())));
				Renderer::submit(m_ShaderSquare, m_SquareVA, transform);
			}
		
		Renderer::submit(m_Shader, m_VertexArray);
	}
	Renderer::endScene();
}
