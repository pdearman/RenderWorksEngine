#pragma once

#ifdef RWE_PLATFORM_WINDOWS
	#ifdef RWE_BUILD_DLL
		#define RWE_API __declspec(dllexport)
	#else
		#define RWE_API __declspec(dllimport)
	#endif
#else
	#error RWE currently only runs on Windows.
#endif

#ifdef RWE_ENABLE_ASSERTS
	#define RWE_ASSERT(x, ...) { if(!(x)) { RWE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define RWE_CORE_ASSERT(x, ...) { if(!(x)) { RWE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define RWE_ASSERT(x, ...)
	#define RWE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)