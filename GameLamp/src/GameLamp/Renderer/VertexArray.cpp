#include "pch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "GameLamp\Platform\OpenGL\OpenGLVertexArray.h"

namespace GameLamp {
	
	VertexArray* VertexArray::create()
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
				return new OpenGLVertexArray();
			}
		};

		GL_CORE_ASSERT(false, "Unknown RendererAPI");

		return nullptr;
	}
}
