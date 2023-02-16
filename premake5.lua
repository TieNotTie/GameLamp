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
IncludeDir["ImGui"] = "GameLamp/vendor/ImGui"

include "GameLamp/vendor/GLFW"
include "GameLamp/vendor/GLAD"
include "GameLamp/vendor/ImGui"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GameLamp"
	location "GameLamp"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("intermediates/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "GameLamp/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.ImGui}",
	}

	links
	{
		"GLFW",
		"GLAD",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GL_BULD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("xcopy \"..\\bin\\Debug-windows-x86_64\\GameLamp\\GameLamp.dll\" \"..\\bin\\Debug-windows-x86_64\\Sandbox\" /q /e /y /i")
		}

	filter "configurations:Debug"
		defines "GL_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "GL_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "GL_DIST"
		buildoptions "/MD"
		optimize "On"

	filter { "system:windows", "configurations:Release"}
		buildoptions "/MT"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		"GameLamp/src"
	}

	links
	{
		"GameLamp"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines "GL_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "GL_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "GL_DIST"
		buildoptions "/MD"
		optimize "On"

	-- filter { "system:windows", "configurations:Release"}
	-- 	buildoptions "/MT"
