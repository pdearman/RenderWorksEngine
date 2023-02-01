#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace RWE
{
	class RWE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core logging
#define RWE_CORE_TRACE(...)			::RWE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RWE_CORE_INFO(...)			::RWE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RWE_CORE_WARN(...)			::RWE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RWE_CORE_ERROR(...)			::RWE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RWE_CORE_FATAL(...)		::RWE::Log::GetCoreLogger()->fatal(__VA_ARGS__)
//#define RWE_CORE_CRITICAL(...)		::RWE::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client logging
#define RWE_TRACE(...)				::RWE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RWE_INFO(...)				::RWE::Log::GetClientLogger()->info(__VA_ARGS__)
#define RWE_WARN(...)				::RWE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RWE_ERROR(...)				::RWE::Log::GetClientLogger()->error(__VA_ARGS__)
#define RWE_FATAL(...)			::RWE::Log::GetClientLogger()->fatal(__VA_ARGS__)
//#define RWE_CRTIICAL(...)			::RWE::Log::GetClientLogger()->critical(__VA_ARGS__)