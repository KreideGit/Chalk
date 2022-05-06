IncludeDir = {}
IncludeDir["Chalk"]     = "%{wks.location}/Chalk/src"
IncludeDir["GLFW"]      = "%{wks.location}/Chalk/vendor/GLFW/include"
IncludeDir["ImGui"]     = "%{wks.location}/Chalk/vendor/ImGui"
IncludeDir["glad"]      = "%{wks.location}/Chalk/vendor/glad/include"
IncludeDir["glm"]       = "%{wks.location}/Chalk/vendor/glm"
IncludeDir["entt"]      = "%{wks.location}/Chalk/vendor/entt/include"
IncludeDir["spdlog"]    = "%{wks.location}/Chalk/vendor/spdlog/include"
IncludeDir["stb_image"] = "%{wks.location}/Chalk/vendor/stb_image"
IncludeDir["box2d"]     = "%{wks.location}/Chalk/vendor/box2d/include"
IncludeDir["miniaudio"] = "%{wks.location}/Chalk/vendor/miniaudio"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

workspace "Chalk"
    architecture "x64"
    startproject "Blackboard"

    configurations 
    { 
        "Debug", 
        "Release" 
    }

    flags
	{
		"MultiProcessorCompile"
	}

group "Dependencies"
    include "Chalk/vendor/GLFW"
    include "Chalk/vendor/ImGui"
    include "Chalk/vendor/glad"
    include "Chalk/vendor/stb_image"
    include "Chalk/vendor/box2d"
    include "Chalk/vendor/miniaudio"

group ""
    include "Chalk"
    include "Blackboard"

newaction 
{
    trigger = "clean",
    description = "cleans the project folder",
    execute = function()
        os.rmdir("./bin")
        os.rmdir("./bin-int")
        os.rmdir("**./bin")
        os.rmdir("**./bin-int")
        os.rmdir("**./.vs")
        os.remove("**.sln")
        os.remove("**.vcxproj")
        os.remove("**.vcxproj.filters")
        os.remove("**.vcxproj.user")
        print("Done")
    end
}