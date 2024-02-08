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

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"

group ""

group "Core"
include "GameLamp"
group ""

include "Sandbox"
