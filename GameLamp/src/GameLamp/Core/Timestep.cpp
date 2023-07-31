#include "pch.h"
#include "Timestep.h"

#include "GLFW/glfw3.h"

namespace GameLamp::Time {
	float getSystemTime()
	{
		return (float)glfwGetTime();
	}
}