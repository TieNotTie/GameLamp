#pragma once

#include "Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace GameLamp{

	class GL_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return m_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return m_ClientLogger;  }
	
	private: 
		static std::shared_ptr<spdlog::logger> m_CoreLogger;
		static std::shared_ptr<spdlog::logger> m_ClientLogger;
	};

}

// Core log macros
#define GL_CORE_INFO(...)	::GameLamp::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GL_CORE_WARN(...)	::GameLamp::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GL_CORE_ERROR(...)	::GameLamp::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GL_CORE_CRITICAL(...)	::GameLamp::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client app log macros
#define GL_CLIENT_INFO(...)		::GameLamp::Log::GetClientLogger()->info(__VA_ARGS__)
#define GL_CLIENT_WARN(...)		::GameLamp::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GL_CLIENT_ERROR(...)	::GameLamp::Log::GetClientLogger()->error(__VA_ARGS__)
#define GL_CLIENT_CRITICAL(...)	::GameLamp::Log::GetClientLogger()->critical(__VA_ARGS__)
