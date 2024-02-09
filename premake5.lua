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
