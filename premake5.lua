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
	IncludeDir["Glad"] = "RenderWorksEngine/tplibs/glad/include"
	IncludeDir["ImGui"] = "RenderWorksEngine/tplibs/imgui"

	include "RenderWorksEngine/tplibs/glfw"
	include "RenderWorksEngine/tplibs/glad"
	include "RenderWorksEngine/tplibs/imgui"

	project "RenderWorksEngine"
		location "RenderWorksEngine"
		kind "SharedLib"
		language "C++"
		toolset "msc-v142"

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
			"%{IncludeDir.Glad}",
			"%{IncludeDir.ImGui}",
		}

		links
		{
			"GLFW",
			"Glad",
			"ImGui",
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
				"GLFW_INCLUDE_NONE",
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
		toolset "msc-v142"

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