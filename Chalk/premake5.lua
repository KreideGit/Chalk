project "Chalk"
    kind "StaticLib"
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
        "src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glad}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.entt}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.stb_image}",
        "%{IncludeDir.box2d}",
        "%{IncludeDir.miniaudio}"
    }

    links
    {
        "GLFW",
        "ImGui",
        "glad",
        "stb_image",
        "box2d",
        "miniaudio"
    }

    defines
	{
		"_CRT_SECURE_NO_WARNINGS"
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