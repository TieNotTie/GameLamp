#pragma once
#pragma once

#include "GameLamp/Core/Base.h"
#include "GameLamp/Core/Log.h"
#include <filesystem>

#ifdef GL_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define GL_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { GL##type##ERROR(msg, __VA_ARGS__); GL_DEBUGBREAK(); } }
#define GL_INTERNAL_ASSERT_WITH_MSG(type, check, ...) GL_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define GL_INTERNAL_ASSERT_NO_MSG(type, check) GL_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", GL_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define GL_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define GL_INTERNAL_ASSERT_GET_MACRO(...) GL_EXPAND_MACRO( GL_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, GL_INTERNAL_ASSERT_WITH_MSG, GL_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define GL_ASSERT(...) GL_EXPAND_MACRO( GL_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define GL_CORE_ASSERT(...) GL_EXPAND_MACRO( GL_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define GL_ASSERT(...)
#define GL_CORE_ASSERT(...)
#endif
