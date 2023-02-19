#include "pch.h"
#include "Buffer.h"

#include "GameLamp/Platform/OpenGL/OpenGLBuffer.h"
#include "GameLamp/Renderer/Renderer.h"

namespace GameLamp {

	VertexBuffer* VertexBuffer::create(float* vertices, uint32_t size)
	{
		switch (Renderer::getAPI())
		{
		case RendererAPI::None:
		{
			GL_CORE_ASSERT(false, "RendererAPI::None is currently not supported");
			break;
		}
		case RendererAPI::OpenGL:
		{
			return new OpenGLVertexBuffer(vertices, size);
		}
		};

		GL_CORE_ASSERT(false, "Unknown RendererAPI");

		return nullptr;
	}

	IndexBuffer* IndexBuffer::create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::getAPI())
		{
		case RendererAPI::None:
		{
			GL_CORE_ASSERT(false, "RendererAPI::None is currently not supported");
			break;
		}
		case RendererAPI::OpenGL:
		{
			return new OpenGLIndexBuffer(indices, size);
		}
		};

		GL_CORE_ASSERT(false, "Unknown RendererAPI");

		return nullptr;
	}

} // namespace GameLamp
