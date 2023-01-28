#pragma once

#include "Core.h"

namespace RWE {

	class RWE_API RWEApp
	{
	public:
		RWEApp();
		virtual ~RWEApp();

		void Run();
	};

	// Projects that use RWE must define this function.
	RWEApp* CreateRWEApp();

}

