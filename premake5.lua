workspace "RenderWorksEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	-- Include directories relative to root folder (solution directory)
	IncludeDir = {}
	IncludeDir["GLFW"] = "RenderWorksEngine/tplibs/glfw/include"

	include "RenderWorksEngine/tplibs/glfw"

	project "RenderWorksEngine"
		location "RenderWorksEngine"
		kind "SharedLib"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		pchheader "rwepch.h"
		pchsource "RenderWorksEngine/source/rwepch.cpp"

		files
		{
			"%{prj.name}/source/**.h",
			"%{prj.name}/source/**.cpp",
		}

		includedirs
		{
			"%{prj.name}/source",
			"%{prj.name}/tplibs/spdlog/include",
			"%{IncludeDir.GLFW}",
		}

		links
		{
			"GLFW",
			"opengl32.lib",
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"

			defines
			{
				"RWE_PLATFORM_WINDOWS",
				"RWE_BUILD_DLL",
			}

			postbuildcommands
			{
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/RWEGame")
			}

		filter "configurations:Debug"
		defines "RWE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "RWE_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "RWE_DIST"
		buildoptions "/MD"
		optimize "On"

	project "RWEGame"
		location "RWEGame"
		kind "ConsoleApp"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files
		{
			"%{prj.name}/source/**.h",
			"%{prj.name}/source/**.cpp",
		}

		includedirs
		{
			"RenderWorksEngine/tplibs/spdlog/include",
			"RenderWorksEngine/source",
		}

		links
		{
			"RenderWorksEngine"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"

			defines
			{
				"RWE_PLATFORM_WINDOWS",
			}

		filter "configurations:Debug"
			defines "RWE_DEBUG"
			buildoptions "/MDd"
			symbols "On"

		filter "configurations:Release"
			defines "RWE_RELEASE"
			buildoptions "/MD"
			optimize "On"

		filter "configurations:Dist"
			defines "RWE_DIST"
			buildoptions "/MD"
			optimize "On"