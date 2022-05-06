project "Blackboard"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "src/**.h", 
        "src/**.cpp" 
    }

    includedirs
    {
        "%{IncludeDir.Chalk}"
    }

    links 
    { 
        "Chalk"
    }

    filter "system:windows"
		systemversion "latest"

    filter "configurations:Debug"
        defines "CK_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "CK_RELEASE"
        runtime "Release"
        optimize "On"