#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "RWE/Log.h"


// PLATFORM SPECIFIC
#ifdef RWE_PLATFORM_WINDOWS
	#include <Windows.h>
	#define _CRT_SECURE_NO_WARNINGS
#endif