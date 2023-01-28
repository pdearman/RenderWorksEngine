#include "Application.h"
#include <stdio.h>

namespace RWE
{
	Application::Application()
	{

	}
	Application::~Application()
	{

	}

	void Application::Run()
	{
		printf("It's running!");
		while (true);
	}
}