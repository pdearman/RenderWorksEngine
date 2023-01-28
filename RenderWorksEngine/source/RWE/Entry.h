#pragma once

#ifdef RWE_PLATFORM_WINDOWS

extern RWE::RWEApp* RWE::CreateRWEApp();

int main(int argc, char** argv)
{
	auto app = RWE::CreateRWEApp();
	app->Run();
	delete app;

	return 0;
}

#endif