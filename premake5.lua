workspace "GameLamp"
    architecture "x64"

    -- TODO: Change to real
    startproject "Sandbox"
    configurations
    {
        "Debug",
        "Release",
        "Shipping"
    }

    filter "configurations:Debug"
        defines { "GL_DEBUG_BUILD" }

    filter "configurations:Release"
        defines { "GL_RELEASE_BUILD" }
      
    filter "configurations:Shipping"
        defines { "GL_SHIPPING_BUILD" }

language "C++"
cppdialect "C++20"


root_dir = os.getcwd()

ROOT_DIR = root_dir

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
include "GameLamp/vendor/glfw"
include "GameLamp/vendor/glad"
include "GameLamp/vendor/imgui" 
group ""

group "Core"
include "GameLamp"
group ""

include "Sandbox"
