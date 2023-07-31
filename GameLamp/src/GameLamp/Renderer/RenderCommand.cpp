#include "pch.h"
#include "RenderCommand.h"

#include "GameLamp\Platform\OpenGL\OpenGLRendererAPI.h"

namespace GameLamp {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}
