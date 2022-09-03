#include "pch.h"

#include "Log.h"
#include "GameLamp/Event/Event.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace GameLamp {

	std::shared_ptr<spdlog::logger> Log::m_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::m_ClientLogger;

	void Log::init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		m_CoreLogger = spdlog::stdout_color_mt("GameLamp");
		m_CoreLogger->set_level(spdlog::level::info);

		m_ClientLogger = spdlog::stdout_color_mt("Client");
		m_ClientLogger->set_level(spdlog::level::info);

	}
}
