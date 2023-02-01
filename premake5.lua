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
	IncludeDir["glfw"] = "RenderWorksEngine/tplibs/glfw/include"

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
			"%{IncludeDir.glfw}",
		}

		links
		{
			"glfw",
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
				--"WIN_DLL",
			}

			postbuildcommands
			{
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/RWEGame")
			}

		filter "configurations:Debug"
			defines
			{
				"RWE_DEBUG",
				"_DEBUG",
				"_CONSOLE",
				"RWE_ENABLE_ASSERTS",
			}
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines
			{
				"RWE_RELEASE",
				"NDEBUG",
				"_CONSOLE",
			}
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines
			{
				"RWE_DIST",
				"NDEBUG",
				--"_CONSOLE",
			}
			runtime "Release"
			optimize "on"

		--[[filters { "system:windows", "configurations:release" }
			buildoptions "/MT"]]--


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
				--"WIN_DLL",
			}

		filter "configurations:Debug"
			defines
			{
				"RWE_DEBUG",
				"_DEBUG",
				"_CONSOLE",
			}
			symbols "On"

		filter "configurations:Release"
			defines
			{
				"RWE_RELEASE",
				"NDEBUG",
				"_CONSOLE",
			}
			optimize "On"

		filter "configurations:Dist"
			defines
			{
				"RWE_DIST",
				"NDEBUG",
				--"_CONSOLE",
			}
			optimize "On"