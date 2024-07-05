#pragma once
#include "includes.h"
#include "SDK.hpp"

using namespace SDK;

inline void mousemove(float tarx, float tary, int smooth)
{
	float ScreenCenterX = (1920 / 2);
	float ScreenCenterY = (1080 / 2);
	float TargetX = 0;
	float TargetY = 0;

	smooth = smooth + 3;

	if (tarx != 0)
	{
		if (tarx > ScreenCenterX)
		{
			TargetX = -(ScreenCenterX - tarx);
			TargetX /= smooth;
			if (TargetX + ScreenCenterX > ScreenCenterX * 2) TargetX = 0;
		}

		if (tarx < ScreenCenterX)
		{
			TargetX = tarx - ScreenCenterX;
			TargetX /= smooth;
			if (TargetX + ScreenCenterX < 0) TargetX = 0;
		}
	}

	if (tary != 0)
	{
		if (tary > ScreenCenterY)
		{
			TargetY = -(ScreenCenterY - tary);
			TargetY /= smooth;
			if (TargetY + ScreenCenterY > ScreenCenterY * 2) TargetY = 0;
		}

		if (tary < ScreenCenterY)
		{
			TargetY = tary - ScreenCenterY;
			TargetY /= smooth;
			if (TargetY + ScreenCenterY < 0) TargetY = 0;
		}
	}
	mouse_event(MOUSEEVENTF_MOVE, static_cast<DWORD>(TargetX), static_cast<DWORD>(TargetY), NULL, NULL);
}

struct Bone {
    int start;
    int end;
};

inline constexpr Bone makeBone(int start, int end) {
    return { start, end };
}


inline constexpr std::array<Bone, 25> bones_map{
    makeBone(9, 7),
    makeBone(7, 100),
    makeBone(100, 98),
    makeBone(98, 93), 
    makeBone(93, 60), 
    makeBone(60, 84), 
    makeBone(7, 54), 
    makeBone(54, 51), 
    makeBone(51, 46), 
    makeBone(46, 13), 
    makeBone(13, 14), 
    makeBone(7, 6), 
    makeBone(6, 5), 
    makeBone(5, 4), 
    makeBone(4, 3), 
    makeBone(3, 2), 
    makeBone(2, 1), 
    makeBone(1, 120), 
    makeBone(120, 112), 
    makeBone(112, 154), 
    makeBone(154, 110),  
    makeBone(1, 142), 
    makeBone(142, 140),  
    makeBone(140, 134), 
    makeBone(134, 132)
};

inline void DrawBones(SDK::USkeletalMeshComponent* mesh, SDK::APlayerController* controller, ImColor color)
{

    for (int i = 0; i < bones_map.size(); i++)
    {
        /*if (!mesh) continue;*/

        SDK::FVector bone_location1 = mesh->GetSocketLocation(mesh->GetBoneName(bones_map[i].start));
        SDK::FVector bone_location2 = mesh->GetSocketLocation(mesh->GetBoneName(bones_map[i].end));

        SDK::FVector2D bone1_w2s_2D{};
        SDK::FVector2D bone2_w2s_2D{};

        if (controller->ProjectWorldLocationToScreen(bone_location1, &bone1_w2s_2D, false) &&
            controller->ProjectWorldLocationToScreen(bone_location2, &bone2_w2s_2D, false))
        {
            Vec2 bone1_w2s = { bone1_w2s_2D.X, bone1_w2s_2D.Y };
            Vec2 bone2_w2s = { bone2_w2s_2D.X, bone2_w2s_2D.Y };

            ESP::DrawLine(bone1_w2s, bone2_w2s, color);
        }
    }
}

//inline SDK::FName StrToName(const wchar_t* str)
//{
//    return SDK::UKismetStringLibrary::Conv_StringToName(SDK::FString(TEXT(str)));
//}

inline SDK::FName StrToName(std::string str)
{
    std::wstring wstr(str.begin(), str.end());
    const wchar_t* wstr_cstr = wstr.c_str();

    return SDK::UKismetStringLibrary::Conv_StringToName(SDK::FString(TEXT(wstr_cstr)));
}

namespace Locations
{
    struct Location {
        std::string name;
        float x, y, z;
    };

    inline std::vector<Location> LocationsReaded{};

    inline std::string getAppDataLocalPath() {
        char* appDataPath;
        size_t len;
        _dupenv_s(&appDataPath, &len, "LOCALAPPDATA");
        std::string path(appDataPath);
        free(appDataPath);
        return path;
    }

    inline void writeLocationToFile(const std::string& filePath, const Location& location) {
        std::ofstream file(filePath, std::ios::app);
        if (file.is_open()) {
            file << location.name << " " << location.x << " " << location.y << " " << location.z << std::endl;
            file.close();
        }
    }

    inline std::vector<Location> readLocationsFromFile(const std::string& filePath) {
        std::vector<Location> locations;
        std::ifstream file(filePath);

        if (file.is_open()) {
            std::string name;
            float x, y, z;
            while (file >> name >> x >> y >> z) {
                locations.push_back({ name, x, y, z });
            }
            file.close();
        }

        return locations;
    }

    inline void saveAllLocationsToFile(const std::string& filePath, std::vector<Location>& locations) {
        std::ofstream file(filePath);
        if (file.is_open()) {
            for (const auto& location : locations) {
                file << location.name << " " << location.x << " " << location.y << " " << location.z << std::endl;
            }
            file.close();
        }
    }

    inline void deleteLocationFromFile(const std::string& filePath, const std::string& name) {
        std::vector<Location> locations = readLocationsFromFile(filePath);
        locations.erase(
            std::remove_if(locations.begin(), locations.end(),
                [&name](const Location& loc) { return loc.name == name; }),
            locations.end());
        saveAllLocationsToFile(filePath, locations);
    }
}

inline std::string GetInfluencerName(const std::string& input) {
    const std::string prefijo = "NPCInflu";
    const std::string sufijo = "_C";


    size_t posInicio = input.find(prefijo);

    posInicio += prefijo.length();

    size_t posFin = input.find(sufijo, posInicio);

    std::string nombre = input.substr(posInicio, posFin - posInicio);

    return nombre;
}




