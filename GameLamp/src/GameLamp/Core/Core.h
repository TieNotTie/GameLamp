#pragma once

#include "PlatformDetection.h"

#ifdef GL_PLATFORM_WINDOWS

	#if GL_DYNAMIC_LINK
		#ifdef GL_BULD_DLL
			#define GL_API __declspec(dllexport)
		#else 
			#define GL_API __declspec(dllimport)
		#endif  // GL_BULD_DLL
	#else 
	#define GL_API
	#endif

	#ifdef GL_ENABLE_ASSERTS
		#define GL_ASSERT(x, ...) { if (!(x)) { GL_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
		#define GL_CORE_ASSERT(x, ...) {if (!(x)) { GL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#else 
		#define GL_ASSERT(x, ...)
		#define GL_CORE_ASSERT(x, ...)
	#endif


#else 
	#error THE WINDOWS IS ONLY SUPPORTED
#endif  // GL_PLATFORM_WINDOWS
