#include "pch.h"
#include "Shader.h"

#include "Renderer.h"
#include "GameLamp\Platform\OpenGL\OpenGLShader.h"

namespace GameLamp {
	
	Shader* Shader::create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::getAPI())
		{
		case RendererAPI::API::None:
		{
			GL_CORE_ASSERT(false, "RendererAPI::None is currently not supported");
			break;
		}
		case RendererAPI::API::OpenGL:
		{
			return new OpenGLShader(vertexSrc, fragmentSrc);
		}
		};

		GL_CORE_ASSERT(false, "Unknown RendererAPI");

		return nullptr;
	}
}
