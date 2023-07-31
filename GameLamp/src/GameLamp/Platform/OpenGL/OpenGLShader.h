#pragma once

#include "GameLamp/Renderer/Shader.h"

#include <glm/glm.hpp>

namespace GameLamp {

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader();

		void bind() const override;
		void unbind() const override;




		void uploadUniform(const std::string& uniformName, int value);
		void uploadUniform( const std::string& uniformName, float value);
		
		void uploadUniform(const std::string& uniformName, const glm::vec2& value);
		void uploadUniform(const std::string& uniformName, const glm::vec3& value);
		void uploadUniform(const std::string& uniformName, const glm::vec4& value);

		void uploadUniform(const std::string& uniformName, const glm::mat3& value);
		void uploadUniform(const std::string& uniformName, const glm::mat4& value);
	private:
		uint32_t m_RendererID;
	};

#if defined(GL_USE_TEMPLATES)



#endif
}; // namespace GameLamp

