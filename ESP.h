#pragma once
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include "Vector.h"
#include <array>
#include "globals.h"

constexpr Vec2 ScreenCenter{ 1920 / 2, 1080 / 2 };
constexpr float PI{ 3.14f };

namespace ESP
{
	inline void DrawBox(Vec2 A, Vec2 B, ImColor color, bool outline = true, float rounding = 0.f, float t = 1.f)
	{
		if (!outline)
			draw_list->AddRect(A.ToImVec2(), B.ToImVec2(), color, rounding, t);
		else
		{
			draw_list->AddRect(A.ToImVec2(), B.ToImVec2(), color, rounding, t);
			draw_list->AddRect({A.x + 1, A.y + 1}, {B.x - 1, B.y - 1}, Colors::Black, rounding, t);
			draw_list->AddRect({A.x - 1, A.y - 1}, {B.x + 1, B.y + 1}, Colors::Black, rounding, t);
		}
	}
	inline void DrawLine(Vec2 A, Vec2 B, ImColor color, bool outline = true, float t = 1.f)
	{
		if (!outline)
			draw_list->AddLine(A.ToImVec2(), B.ToImVec2(), color, t);
		else
		{
			draw_list->AddLine(A.ToImVec2(), B.ToImVec2(), Colors::Black, t+1);
			draw_list->AddLine(A.ToImVec2(), B.ToImVec2(), color, t);
		}
	}
	inline void DrawCircle(Vec2 pos, float r, ImColor color, int segments = 12, float t = 1.f)
	{
		draw_list->AddCircle(pos.ToImVec2(), r, color, segments, t);
	}
	inline void DrawCircleFilled(Vec2 pos, float r, ImColor color, int segments = 12)
	{
		draw_list->AddCircleFilled(pos.ToImVec2(), r, color, segments);
	}
	inline void DrawBoxFilled(Vec2 A, Vec2 B, ImColor color, float rounding = 0.f, float t = 1.f)
	{
		draw_list->AddRectFilled(A.ToImVec2(), B.ToImVec2(), color, rounding);
	}
	inline void DrawCorneredBox(Vec2 A, Vec2 B, float w, float h, ImColor color, bool outline = true)
	{
		const float wi = w / 3;
		const float hi = h / 3;

		DrawLine({ A.x - w, A.y }, { A.x - w + wi, A.y }, color);
		DrawLine({ A.x + w, A.y }, { A.x + w - wi, A.y }, color);

		DrawLine({ A.x - w, A.y }, { A.x - w, A.y + hi }, color);
		DrawLine({ A.x + w, A.y }, { A.x + w, A.y + hi }, color);

		DrawLine({ B.x - w, B.y }, { B.x - w + wi, B.y }, color);
		DrawLine({ B.x + w, B.y }, { B.x + w - wi, B.y }, color);

		DrawLine({ B.x - w, B.y }, { B.x - w, B.y - hi }, color);
		DrawLine({ B.x + w, B.y }, { B.x + w, B.y - hi }, color);
	}
	inline void DrawCrosshair(float size, float t, ImColor color)
	{
		DrawLine({ ScreenCenter.x - size, ScreenCenter.y }, { ScreenCenter.x + size, ScreenCenter.y }, color, true, t);
		DrawLine({ ScreenCenter.x, ScreenCenter.y - size }, { ScreenCenter.x, ScreenCenter.y + size }, color, true, t);
	}
	inline void DrawText2(Vec2 pos, ImColor color, const char* text)
	{
		draw_list->AddText(ImVec2(pos.x, pos.y), color, text);
	}
}