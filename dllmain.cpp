#include <windows.h>

struct stMain {
	stMain() {
		VirtualProtect(reinterpret_cast<LPVOID>(0x73558B), 0x2, PAGE_READWRITE, &oldProt);
		memset(reinterpret_cast<void*>(0x73558B), 0x90, 0x2);
		VirtualProtect(reinterpret_cast<LPVOID>(0x73558B), 0x2, oldProt, &oldProt);
	};
	~stMain() {
		VirtualProtect(reinterpret_cast<LPVOID>(0x73558B), 0x2, PAGE_READWRITE, &oldProt);
		memcpy(reinterpret_cast<void*>(0x73558B), "\x74\x3C", 0x2);
		VirtualProtect(reinterpret_cast<LPVOID>(0x73558B), 0x2, oldProt, &oldProt);
	};
	DWORD oldProt;
} plugin;
