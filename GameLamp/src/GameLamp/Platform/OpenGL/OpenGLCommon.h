#pragma once

#include "GameLamp/Renderer/Buffer.h"
#include "GameLamp/Core/Assert.h"

#include "glad/glad.h"

namespace GameLamp {

	inline GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
			case ShaderDataType::Bool:	 return GL_BOOL;
			case ShaderDataType::Int:	 return GL_INT;
			case ShaderDataType::Int2:	 return GL_INT;
			case ShaderDataType::Int3:	 return GL_INT;
			case ShaderDataType::Int4:	 return GL_INT;
			case ShaderDataType::Float:	 return GL_FLOAT;
			case ShaderDataType::Float2: return GL_FLOAT;
			case ShaderDataType::Float3: return GL_FLOAT;
			case ShaderDataType::Float4: return GL_FLOAT;
			case ShaderDataType::Mat3:	 return GL_FLOAT;
			case ShaderDataType::Mat4:	 return GL_FLOAT;
		}

		GL_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}
}
