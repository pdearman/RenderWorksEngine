#pragma once

#ifdef RWE_PLATFORM_WINDOWS

extern RWE::RWEApp* RWE::CreateRWEApp();

int main(int argc, char** argv)
{

	RWE::Log::Init();
	RWE_CORE_WARN("Initialized spdlog \"CoreLogger\"...");
	int a = 7;
	RWE_INFO("Initialized spdlog \"ClientLogger\"... Var={0}", a);

	auto RWEApp = RWE::CreateRWEApp();
	RWEApp->Run();
	delete RWEApp;

	return 0;
}

#endif