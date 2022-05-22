#pragma once
#include "Windows.h"

DWORD dwForceJump = 0x527D360;

struct world {

	DWORD GameModule = (DWORD)GetModuleHandle("client.dll");
};

struct entity {
public:
	int health;
	int flags;

	DWORD EnitityPtr;

	void ForceJump(DWORD GameModule) {

		*(int*)(GameModule + dwForceJump) = 2;
	}
};


struct Offsets {
public:
	DWORD dwLocalPlayer = 0xDB75DC;
	DWORD m_iHealth = 0x100;
	DWORD m_fFlags = 0x104;
};