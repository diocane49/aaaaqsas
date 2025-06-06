#pragma once
#include <algorithm>
#include <array>
#include <cctype>
#include <chrono>
#include <codecvt>               
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <dwmapi.h>
#include <emmintrin.h>
#include <filesystem>
#include <format>
#include <fstream>
#include <immintrin.h>
#include <iostream>
#include <locale>                
#include <map>
#include <memory>
#include <mutex>
#include <psapi.h>
#include <random>
#include <shlobj.h>
#include <softintrin.h>
#include <sstream>
#include <stdio.h>
#include <string>
#include <string_view>
#include <sys/stat.h>
#include <tchar.h>
#include <thread>
#include <TlHelp32.h>
#include <tmmintrin.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <Windows.h>
#include <xmmintrin.h>

#include "xorstr.h"

inline std::mutex skeletonMutex;

#define PI (3.14159265358979323846264338327950288419716939937510f)
#define print(x,...) printf_s(x,__VA_ARGS__)
#define IMGUI_DEFINE_MATH_OPERATORS
#define STB_IMAGE_IMPLEMENTATION
#define xor(str) xorstr(str).crypt_get()

//Vers�o do GTA (Obrigat�rio deixar apenas 1 defini��o.)
//
//#define GTARageMP
#define GTAFiveM
//#define GTAOnline


//Definindo Nosafer, o executavel n�o estara safe para usar WBAND com motorista.
//
#define _NOSAFER


//Edi��o do menu (Habilita apenas o menu Obs: Deve-se deixar o bloco de notas para o cheat dar atach)
// 
//#define ONLY_MENU


//Dev Options
//#define __VERBOSE
//#define DUMP
//#define _DEBUG
//#define _DUMPLOOP
 

//Ovelay Options  (Deixar sem defini��es usar� o DirectX11 padr�o)
// 
//#define __NVidiaAMD
//#define __Medal
#define WBAND


//N�o mexer!
#ifdef __NVidiaAMD
#define _DirectX9
#elif defined(__Medal)
#define _DirectX9
#else
#define _DirectX11
#endif
#ifdef GTARageMP
#define GAME_NAME "GTARageMP"
#elif defined(GTAOnline)
#define GAME_NAME "GTAOnline"
#endif

#ifndef __NVidiaAMD
#include <d3d11.h>
#include <d3d9.h>
#include <d3dx9math.h>
#include <dxgi.h>
#pragma comment(lib, "d3d11.lib")
#endif

#ifdef __NVidiaAMD
#include <d3d9.h>
#include <d3dx9.h>
#include <dxgi.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dwmapi.lib")
#include "imgui/imgui_impl_dx9.h"
#endif

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"

#ifndef __NVidiaAMD
#include "imgui/imgui_impl_dx11.h"
#endif

#include "imgui/imgui_impl_win32.h"
#include "imgui/etc_elements.h"
#include "imgui/nav_elements.h"

