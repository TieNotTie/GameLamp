project "GameLamp"
    kind "StaticLib"

    targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "src/**.h",
        "src/**.c",
        "src/**.hpp",
        "src/**.cpp",
    }

    includedirs
    {
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
    }
