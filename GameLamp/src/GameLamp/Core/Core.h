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

#include "Assert.h"


#else 
	#error THE WINDOWS IS ONLY SUPPORTED
#endif  // GL_PLATFORM_WINDOWS
