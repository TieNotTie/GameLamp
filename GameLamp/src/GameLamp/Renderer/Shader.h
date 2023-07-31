#pragma once

#include <glm/glm.hpp>

#include <string>

namespace GameLamp {

	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		static Shader* create(const std::string& vertexSrc, const std::string& fragmentSrc);
	};

}; // namespace GameLamp
