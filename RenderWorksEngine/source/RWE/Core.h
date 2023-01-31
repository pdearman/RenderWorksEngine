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

#define BIT(x) (1 << x)


/////////////////////////////////////
// TEMPORARY INCLUDES ///////////////
/////////////////////////////////////
#include <stdio.h>