#include "CoreInitializer.h"

#include "Core/Log.h"
#include "Util/Time.h"

namespace Lamp {

	void CoreInitializer::InitCoreModules()
	{
		static bool CoreInited = false;
		GL_CORE_ASSERT(!CoreInited && "Core Already inited!");
		bool result = true;

		// Init logging system
		Logger::Init();
		GL_CORE_INFO("Logger initialized");

		// Init time measurement system
		result = SetupTimeMeasurement();
		GL_CORE_ASSERT(result && "Failed to Setup Time Measurement");

		// Init graphics api

		// Init imgui

		CoreInited = true;
	}

}

