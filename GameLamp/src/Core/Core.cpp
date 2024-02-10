#include "Core.h"

#include "Util/Time.h"

#include <cassert>

namespace Lamp {

	bool CoreInit()
	{
		bool result = true;

		result = SetupTimeMeasurement();
		assert(result && "Failed to Setup Time Measurement");


		return result;
	}
}

