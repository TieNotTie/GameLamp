project "GameLamp"
    kind "StaticLib"

    targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

    filter "system:windows"
		defines 
		{ 
			"GL_PLATFORM_WINDOWS",
		}

    files {
        "src/**.h",
        "src/**.c",
        "src/**.hpp",
        "src/**.cpp",
    }

    includedirs
    {
        "src/",
        "vendor/glm/glm",
        "vendor/spdlog/include",
        "vendor/imgui",
        "vendor/glfw/include",
        "vendor/glad/include",
    }
    
    links 
    {
        "GLFW",
        "ImGui",
        "GLAD", 
        "opengl32.lib"
    }
