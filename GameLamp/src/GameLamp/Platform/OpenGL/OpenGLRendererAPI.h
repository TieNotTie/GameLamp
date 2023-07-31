#pragma once

#include "GameLamp/Renderer/RendererAPI.h"

namespace GameLamp {

	class OpenGLRendererAPI : public RendererAPI {
	public:
		virtual void setClearColor(const glm::vec4& color) override;
		virtual void clear() override;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
	};

}
