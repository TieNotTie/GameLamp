workspace "GameLamp"
	architecture "x64"

	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
-- Include directories relative to the Solution root
IncludeDir = {}
IncludeDir["GLFW"] = "GameLamp/vendor/GLFW/include"
IncludeDir["GLAD"] = "GameLamp/vendor/GLAD/include"
IncludeDir["ImGui"] = "GameLamp/vendor/imgui"
IncludeDir["glm"] = "GameLamp/vendor/glm"

include "GameLamp/vendor/GLFW"
include "GameLamp/vendor/GLAD"
include "GameLamp/vendor/imgui"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GameLamp"
	location "GameLamp"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("intermediates/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "GameLamp/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
		{
			"_CRT_SECURE_NO_WARNINGS",
			"GLFW_INCLUDE_NONE"
		}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
	}

	links
	{
		"GLFW",
		"GLAD",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"GL_BULD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "GL_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "GL_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "GL_DIST"
		runtime "Release"
		optimize "on"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("intermediates/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"GameLamp/vendor/spdlog/include",
		"GameLamp/src",
		"%{IncludeDir.glm}",
		"%{IncludeDir.ImGui}",
	}

	links
	{
		"GameLamp",
		"ImGui",
	}

	filter "system:windows"
		staticruntime "on"
		systemversion "latest"

	filter "configurations:Debug"
		defines "GL_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "GL_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "GL_DIST"
		runtime "Release"
		optimize "on"

