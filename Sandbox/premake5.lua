project "Sandbox"
    kind "ConsoleApp"

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
        "../GameLamp/src/",
    }

    links
    {
        "GameLamp",
    }
