#pragma once

#include "VertexArray.h"

#include <glm\glm.hpp>

namespace GameLamp {

	class RendererAPI
	{
	public:

		enum class API
		{
			None = 0, OpenGL = 1
		};

	public:

		virtual void setClearColor(const glm::vec4& color) = 0;
		virtual void clear() = 0;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;

		inline static API getApi() { return s_Api; }
	
	private:
		static API s_Api;
	};

}
