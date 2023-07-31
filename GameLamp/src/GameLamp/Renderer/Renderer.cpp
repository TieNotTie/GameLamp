#include "pch.h"
#include "Renderer.h"

#include "GameLamp/Platform/OpenGL/OpenGLShader.h"

namespace GameLamp {

	Renderer::SceneData* Renderer::m_SceneData = new Renderer::SceneData;

	void Renderer::beginScene(std::shared_ptr<OrthographicCamera> camera)
	{
		m_SceneData->ViewProjectionMatrix = camera->getViewProjectionMatrix();
	}

	void Renderer::endScene()
	{
	}

	void Renderer::submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray, const glm::mat4& transform)
	{ 
		shader->bind();
		std::dynamic_pointer_cast<OpenGLShader>(shader)->uploadUniform("u_ViewProjection", m_SceneData->ViewProjectionMatrix);
		std::dynamic_pointer_cast<OpenGLShader>(shader)->uploadUniform("u_Transform", transform);

		vertexArray->bind();
		RenderCommand::drawIndexed(vertexArray);
	}

} // namespace GameLamp