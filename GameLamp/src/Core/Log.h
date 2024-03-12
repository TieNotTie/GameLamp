#pragma once

#include <spdlog/spdlog.h>
#include <memory>
#include <cassert>

namespace Lamp 
{
	class Logger 
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return m_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return m_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> m_CoreLogger;
		static std::shared_ptr<spdlog::logger> m_ClientLogger;
	};
}

#if defined GL_DEBUG_BUILD
// Debug Configuration
	#define GL_CORE_INFO(...)         ::Lamp::Logger::GetCoreLogger()->info(__VA_ARGS__);
	#define GL_CORE_WARN(...)         ::Lamp::Logger::GetCoreLogger()->warn(__VA_ARGS__);
	#define GL_CORE_ERROR(...)        ::Lamp::Logger::GetCoreLogger()->error(__VA_ARGS__);
	#define GL_CORE_CRITICAL(...)     ::Lamp::Logger::GetCoreLogger()->critical(__VA_ARGS__);
	#define GL_CORE_ASSERT(expression) assert(expression);

	#define GL_CLIENT_INFO(...)       ::Lamp::Logger::GetClientLogger()->info(__VA_ARGS__);
	#define GL_CLIENT_WARN(...)       ::Lamp::Logger::GetClientLogger()->warn(__VA_ARGS__);
	#define GL_CLIENT_ERROR(...)      ::Lamp::Logger::GetClientLogger()->error(__VA_ARGS__);
	#define GL_CLIENT_CRITICAL(...)   ::Lamp::Logger::GetClientLogger()->critical(__VA_ARGS__);
	#define GL_CLIENT_ASSERT(expression) assert(expression);

#elif GL_RELEASE_BUILD 
// Release Configuration
	#define GL_CORE_INFO(...)         // Disable log
	#define GL_CORE_WARN(...)         // Disable log
	#define GL_CORE_ERROR(...)        ::Lamp::Logger::GetCoreLogger()->error(__VA_ARGS__);
	#define GL_CORE_CRITICAL(...)     ::Lamp::Logger::GetCoreLogger()->critical(__VA_ARGS__);
	#define GL_CORE_ASSERT(expression) assert(expression);

	#define GL_CLIENT_INFO(...)       // Disable log
	#define GL_CLIENT_WARN(...)       // Disable log
	#define GL_CLIENT_ERROR(...)      ::Lamp::Logger::GetClientLogger()->error(__VA_ARGS__);
	#define GL_CLIENT_CRITICAL(...)   ::Lamp::Logger::GetClientLogger()->critical(__VA_ARGS__);
	#define GL_CLIENT_ASSERT(expression) assert(expression);

#elif GL_SHIPPING_BUILD
// Shipping Configuration
	#define GL_CORE_INFO(...)         // Disable log
	#define GL_CORE_WARN(...)         // Disable log
	#define GL_CORE_ERROR(...)        // Disable log
	#define GL_CORE_CRITICAL(...)     ::Lamp::Logger::GetCoreLogger()->critical(__VA_ARGS__);
	#define GL_CORE_ASSERT(expression) (void(0))

	#define GL_CLIENT_INFO(...)       // Disable log
	#define GL_CLIENT_WARN(...)       // Disable log
	#define GL_CLIENT_ERROR(...)      // Disable log
	#define GL_CLIENT_CRITICAL(...)   ::Lamp::Logger::GetClientLogger()->critical(__VA_ARGS__);
	#define GL_CLIENT_ASSERT(expression) (void(0))

#endif

