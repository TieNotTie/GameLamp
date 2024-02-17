#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Lamp 
{
	std::shared_ptr<spdlog::logger> Logger::m_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::m_ClientLogger;

	void Logger::Init() 
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		m_CoreLogger = spdlog::stdout_color_mt("GAME_LAMP");
		m_CoreLogger->set_level(spdlog::level::trace);

		m_ClientLogger = spdlog::stdout_color_mt("SANDBOX");
		m_ClientLogger->set_level(spdlog::level::trace);
	}
}
