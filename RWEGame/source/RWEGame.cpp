//#include "rwepch.h"
#include <RenderWorksEngine.h>

class ExampleLayer : public RWE::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{
		//RWE_INFO("ExampleLayer Created");
	}

	void OnUpdate() override
	{
		//RWE_INFO("ExampleLayer::Update");
	}

	void OnEvent(RWE::Event& event) override
	{
		RWE_TRACE("{0}", event);
	}
};

	class RWEGame : public RWE::RWEApp {
	public:
		RWEGame()
		{
			PushLayer(new ExampleLayer());
		}

		~RWEGame()
		{

		}


	};

	RWE::RWEApp* RWE::CreateRWEApp()
	{
		return new RWEGame();
	}