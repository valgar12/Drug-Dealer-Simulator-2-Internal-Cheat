#pragma once
#include <Windows.h>
#include <fstream>
#include <d3d11.h>
#include <dxgi.h>
#include <string>
#include <thread>
#include <cstdint>
#include <vector>
#include "kiero/kiero.h"
#include "ESP.h"
#include "functions.h"
#include "globals.h"
#include "GUI.h";
#include "PlayerCache.h"
#include "ActorsCache.h"
#include "GameLoop.h"


typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;