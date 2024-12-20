#pragma once

#define WIN32_LEAN_AND_MEAN 
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <memory>

#include <array>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <algorithm>

#include <string>
#include <cassert>

#include <io.h>
#include <typeinfo>
#include <filesystem>

#include <Windows.h>
#include <mmsystem.h>
#include <commdlg.h>
#include <iostream>

#include <d3d12.h>
#include <d3d12shader.h>
#include <dxgi1_4.h>
#include <wrl/client.h>
using namespace Microsoft::WRL;


#include <DirectXMath.h>
using namespace DirectX;


#include <Xinput.h>

#include "ImGUI/imgui.h"
#include "ImGUI/imgui_impl_win32.h"
#include "imGUI/imgui_impl_dx12.h"


#pragma comment( lib, "winmm.lib" )
#pragma comment( lib, "d3d12.lib" )
#pragma comment( lib, "dxgi.lib" )
#pragma comment (lib, "xinput.lib")

#define SCREEN_MAX_WIDTH (1280)
#define SCREEN_MAX_HIGHT (720)


HWND GetWindow();
