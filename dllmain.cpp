#include "world.h"

int WINAPI MainThread(HMODULE hModule) {

    world GameWorld;
    entity LocalPlayer;
    Offsets GameInfo;

    while (!GetAsyncKeyState(VK_END)) {

        if (GetAsyncKeyState(VK_SPACE)) {
            LocalPlayer.EnitityPtr = *(DWORD*)(GameWorld.GameModule + GameInfo.dwLocalPlayer);

            if (LocalPlayer.EnitityPtr != NULL) {

                LocalPlayer.health = *(int*)(LocalPlayer.EnitityPtr + GameInfo.m_iHealth);
                LocalPlayer.flags = *(int*)(LocalPlayer.EnitityPtr + GameInfo.m_fFlags);

                if (LocalPlayer.health > 0 && LocalPlayer.flags == 257) {

                    LocalPlayer.ForceJump(GameWorld.GameModule);
                }
            }
        }
    }

    FreeLibraryAndExitThread(hModule, NULL);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)MainThread, hModule, NULL, NULL);
    }
    return TRUE;
}

