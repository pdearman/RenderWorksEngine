#include <RenderWorksEngine.h>

	class RWEGame : public RWE::RWEApp {
	public:
		RWEGame()
		{

		}

		~RWEGame()
		{

		}


	};

	RWE::RWEApp* RWE::CreateRWEApp()
	{
		return new RWEGame();
	}