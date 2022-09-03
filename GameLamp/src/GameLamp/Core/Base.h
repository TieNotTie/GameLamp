#pragma once

#include "GameLamp/Core/PlatformDetection.h"

#ifdef GL_DEBUG
#if defined(GL_PLATFORM_WINDOWS)
#define GL_DEBUGBREAK() __debugbreak()
#elif defined(GL_PLATFORM_LINUX)
#include <signal.h>
#define GL_DEBUGBREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define GL_ENABLE_ASSERTS
#else
#define GL_DEBUGBREAK()
#endif

#define GL_EXPAND_MACRO(x) x
#define GL_STRINGIFY_MACRO(x) #x

#define GL_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

#include "pch.h"

template<typename T>
constexpr auto BIT(T x) { return (1LU << x); }

template<class Base, class Derived>
constexpr bool IS_BASE_OF()
{
    return std::is_base_of<Base, Derived>::value;
}
