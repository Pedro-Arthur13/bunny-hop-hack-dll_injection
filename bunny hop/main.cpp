#define WIN32_LEAN_AND_MEAN // Windowns SDK -> only the essential things
#include <Windows.h>

//header files
#include <cstdint> // stdu and pointer
#include <thread> // sleep the program

namespace offset {
	//client
	constexpr std::ptrdiff_t dwLocalPlayer = 0; // substituir pelos recentes
	constexpr std::ptrdiff_t dwForceJump = 0;

	//player
	constexpr std::ptrdiff_t m_iHeath = 0;
	constexpr std::ptrdiff_t m_fFlags = 0;

}

// hack function
void BunnyHop(const HMODULE instance) noexcept {
	const auto client = reinterpret_cast<std::uintptr_t>(GetModuleHandle("client.dll"));

	//hack loo
	while (!GetAsyncKeyState(VK_END)) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1));

		// confere se o SPACE ta segurado
		if (!GetAsyncKeyState(VK_SPACE))
			continue;

		//get local player
		const auto localPlayer = *reinterpret_cast<std::uintptr_t*>(client + offset::dwLocalPlayer);


		if (!localPlayer)
			continue;
		const auto health = *reinterpret_cast<std::int32_t*>(localPlayer + offset::m_iHeath);

		// to vivo?
		if (!health)
			continue;

		const auto flags = *reinterpret_cast<std::int32_t*>(localPlayer + offset::m_fFlags);

		// ta no chao?
		(flags & (1 << 0)) ?
			*reinterpret_cast<std::uintptr_t*>(client + offset::dwForceJump) = 6 :// force jump
			*reinterpret_cast<std::uintptr_t*>(client + offset::dwForceJump) = 4; // reset

	}
	//uninject
	FreeLibraryAndExitThread(instance, 0);
}

//entry point
int __stdcall DllMain(
	const HMODULE instance, // instance of dll
	const std::uintptr_t reason, //check the reason of attachment/detachment
	const void* reserved // not used
)
{
	// DLL_PROCESS_ATTACH
	if (reason == 1) {
		DisableThreadLibraryCalls(instance);

		//create hack thread
		const auto thread = CreateThread(
			nullptr,
			0,
			reinterpret_cast<LPTHREAD_START_ROUTINE>(BunnyHop),
			instance,
			0,
			nullptr
		);
		if (thread)
			CloseHandle(thread);


	}
	return 1;// allways true
}