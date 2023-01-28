#include <RenderWorksEngine.h>

class RWEGame : public RWE::Application {
public:
	RWEGame()
	{

	}

	~RWEGame()
	{

	}


};

int main()
{
	RWEGame* RWEGame_Running = new RWEGame();
	RWEGame_Running->Run();
	delete RWEGame_Running;

	return 0;
}