#include "Core.h"

#include "Core/Log.h"
#include "Util/Time.h"

namespace Lamp {

	bool CoreInit()
	{
		bool result = true;

		Logger::Init();

		GL_CORE_INFO("Logger initialized");

		result = SetupTimeMeasurement();
		GL_CORE_ASSERT(result && "Failed to Setup Time Measurement");


		return result;
	}
}

