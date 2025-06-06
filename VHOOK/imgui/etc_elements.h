#pragma once

#include <cstdint>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>

#define IMGUI_DEFINE_MATH_OPERATORS

#include "./imgui.h"
#include "./imgui_internal.h"

using namespace ImGui;

namespace e_elements {

    bool begin_child_ex(const char* name, ImGuiID id, const ImVec2& size_arg, bool border, ImGuiWindowFlags flags);
    bool begin_child(const char* str_id, const ImVec2& size = ImVec2(0, 0), bool border = false, ImGuiWindowFlags flags = 0);
    bool begin_child(ImGuiID id, const ImVec2& size = ImVec2(0, 0), bool border = false, ImGuiWindowFlags flags = 0);
    void end_child();
}
