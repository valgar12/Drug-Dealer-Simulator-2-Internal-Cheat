#pragma once
#include "includes.h"
#include "SDK.hpp"

inline bool showmenu = true;
inline bool alive = true;
inline ImDrawList* draw_list{};
inline std::vector<SDK::AActor*> PlayerList{};
inline std::vector<SDK::AActor*> ActorList{};
inline SDK::UEngine* Engine{};
inline SDK::UWorld* World{};
inline SDK::TArray<SDK::AActor*> actors{};
inline SDK::AActor* actor_list{};
inline SDK::APlayerController* MyController{};
inline float aimbot_distance{};

enum BoxTypes
{
	Nornmal = 0,
	Cornered = 1,
	Box_3D = 2
};

struct LocationStruct
{
	SDK::FVector Pos{};
	std::string Name{ "Null" };
};

inline SDK::FName StrToName(std::string str);


inline constexpr LocationStruct makeLocation(SDK::FVector Pos, std::string Name) {
	return { Pos, Name };
}

inline SDK::FInventoryObjectData MakeDrug(std::string ItemID, UC::int32 stack, std::string SubstanceID, float GramAmount) {
	SDK::FInventoryObjectData NewItem{};
	NewItem.ItemId = StrToName(ItemID);
	NewItem.CurStack = stack;
	NewItem.SubstanceContents.SubstanceID = StrToName(SubstanceID);
	NewItem.SubstanceContents.GramAmount = GramAmount;

	return NewItem;
}

inline SDK::FInventoryObjectData MakeItem(std::string ItemID, UC::int32 stack) {
	SDK::FInventoryObjectData NewItem{};
	NewItem.ItemId = StrToName(ItemID);
	NewItem.CurStack = stack;

	return NewItem;
}

namespace mem
{
	inline uintptr_t GameBase{};
}

namespace gl
{
	namespace ESP
	{
		inline bool ESP = true;
		inline bool ESP_Box = false;
		inline bool ESP_CorneredBox = false;
		inline bool ESP_3DBox = false;
		inline bool ESP_Snaplines = true;
		inline bool ESP_Skeleton = true;
		inline bool ESP_Names = false;
		inline bool Police = true;
		inline bool Thugs = true;
		inline bool HealthBar = true;

		inline bool VisCheck = true;

		inline int BoxTypeID = 0;
		inline BoxTypes BoxType = BoxTypes::Nornmal;
		inline const char* BoxTypeArray[3]{ "Normal", "Cornered", "3D Box" };
	}

	namespace Aimbot
	{
		inline bool Aimbot = true;
		inline bool ShowFov = false;
		inline float Fov = 1000.f;
		inline bool VisCheck = false;
		inline float Smooth = 1.f;
	}

	namespace World
	{
		inline bool World = true;
		inline bool Vehicles = true;
		inline bool Boats = true;
		inline bool Shops = true;
		inline bool Influencers = true;
	}

	namespace Exploits
	{
		inline bool InfiniteStamina = false;
		inline bool SuperSpeed = false;
		inline bool FastSwim = false;
		inline bool FastFly = false;
		inline bool GodMode = false;
		inline bool SuperJump = false;
		inline bool FastAcceleration = false;
		inline bool NoWeight = false;
		inline bool UnbreakingWeapons = false;
		inline bool FastMeleeAtack = false;
		inline bool InfiniteFuel = false;
		inline bool InstantCraft = false;
		inline bool SuperFlashlight = false;
		inline int FlashPower = 1000;
		inline int FlashRange = 1000;
		inline SDK::TArray<struct SDK::FInventoryGridData> Inventory;
		inline SDK::TArray<struct SDK::FInventoryGridData> InventoryTest;

		namespace cheats
		{
			inline bool GiveMoneyBank = false;
			inline bool GiveMoneyInventory = false;
			inline bool GiveAllSubstances = false;
			inline bool GiveAllFurtniture = false;
			inline bool GiveCartelXP = false;
			inline bool GiveStreetCreed = false;
			inline bool MaxShopsReputation = false;
			inline bool ClearMapFog = false;
			inline bool ResetMapFog = false;
			inline bool RestockShops = false;
			inline bool SetTime = false;
			inline bool SkipDay = false;
			inline int hour = 12;
			inline bool UnlockAllHideouts = false;
			inline bool GhostMode = false;
			inline bool UnlockAllShopOffers = false;
			inline bool CleanTrashBins = false;
			inline bool UnlockAllVehicles = false;
		}
	}

	namespace Items
	{
		inline int Stack{1};
		inline int GramAmountInt{ 1 };
		inline float GramAmountFloat = static_cast<float>(GramAmountInt);
		inline SDK::FInventoryObjectData CurrentItemToSpawn{};
		inline bool SpawnItem = false;

		inline std::array<SDK::FInventoryObjectData, 6> Drugs{
			MakeDrug("DYN-SUBSTANCE-PACK", Stack, "SUBSTANCE-WEED-SAT", GramAmountFloat),
			MakeDrug("DYN-SUBSTANCE-PACK", Stack, "SUBSTANCE-WEED-IND", GramAmountFloat),
			MakeDrug("DYN-SUBSTANCE-PACK", Stack, "SUBSTANCE-AMPH", GramAmountFloat),
			MakeDrug("DYN-SUBSTANCE-PACK", Stack, "SUBSTANCE-OPIUM", GramAmountFloat),
			MakeDrug("DYN-SUBSTANCE-PACK", Stack, "SUBSTANCE-COCAINE", GramAmountFloat),
			MakeDrug("DYN-SUBSTANCE-PACK", Stack, "SUBSTANCE-METH", GramAmountFloat)
		};

		inline std::array<SDK::FInventoryObjectData, 19> Tools{
			MakeItem("TOOL-COOKING-POT", Stack),
			MakeItem("TOOL-FLASHLIGHT", Stack),
			MakeItem("TOOL-FLASHLIGHT-M", Stack),
			MakeItem("TOOL-CROWBAR", Stack),
			MakeItem("TOOL-WIRE-CUTTERS", Stack),
			MakeItem("TOOL-WEP-HAMMER", Stack),
			MakeItem("TOOL-WEP-SHOVEL", Stack),
			MakeItem("TOOL-MULTITOOL", Stack),
			MakeItem("TOOL-BOLT-CUTTER", Stack),
			MakeItem("TOOL-WEP-KNIFE-MIL", Stack),
			MakeItem("TOOL-MACHETE", Stack),
			MakeItem("TOOL-FLASHLIGHT-HID", Stack),
			MakeItem("TOOL-BULB-UV-L", Stack),
			MakeItem("TOOL-BULB-LED-S", Stack),
			MakeItem("TOOL-HYDRO", Stack),
			MakeItem("TOOL-POT", Stack),
			MakeItem("TOOL-FAN", Stack),
			MakeItem("TOOL-BULB-LED-L", Stack),
			MakeItem("TOOL-DISARM-CARD", Stack)
		};

		inline std::array<SDK::FInventoryObjectData, 33> Items{
			MakeItem("ITEM-WATER-S", Stack),
			MakeItem("ITEM-WATER-L", Stack),
			MakeItem("ITEM-SUGAR-M", Stack),
			MakeItem("ITEM-FLOUR-M", Stack),
			MakeItem("ITEM-SALT-M", Stack),
			MakeItem("ITEM-POPPY-SEEDS-S", Stack),
			MakeItem("ITEM-CIGARETTE-PACK", Stack),
			MakeItem("ITEM-TABACCO-PACK", Stack),
			MakeItem("ITEM-FERTILIZER-M", Stack),
			MakeItem("ITEM-FERTILIZER-L", Stack),
			MakeItem("ITEM-FERTILIZER-SYN-M", Stack),
			MakeItem("ITEM-MOBILE", Stack),
			MakeItem("ITEM-MAP", Stack),
			MakeItem("ITEM-ROLLING-PAPERS", Stack),
			MakeItem("ITEM-GLASS-PIPE", Stack),
			MakeItem("ITEM-PLASTIC-BAGGIES", Stack),
			MakeItem("ITEM-DUCTTAPE", Stack),
			MakeItem("ITEM-STRETCH", Stack),
			MakeItem("ITEM-PLASTIC-BAG", Stack),
			MakeItem("ITEM-BUS-TICKET", Stack),
			MakeItem("ITEM-STASH-FOOD", Stack),
			MakeItem("ITEM-GAS-CANISTER-M", Stack),
			MakeItem("ITEM-GAS-CANISTER-L", Stack),
			MakeItem("ITEM-METAL-PARTS", Stack),
			MakeItem("ITEM-STASH-MED", Stack),
			MakeItem("ITEM-ELEC-WIRES", Stack),
			MakeItem("ITEM-VIAL", Stack),
			MakeItem("ITEM-GLASS-PIPE", Stack),
			MakeItem("ITEM-FIRECRACKER", Stack),
			MakeItem("ITEM-PASS", Stack),
			MakeItem("ITEM-VIAL-LAB", Stack),
			MakeItem("ITEM-BOX-LAB-EMPTY", Stack),
			MakeItem("ITEM-MORPH-VIAL", Stack)
		};
		inline std::array<SDK::FInventoryObjectData, 11> Chems
		{
			MakeItem("CHEM-ETHANOL", Stack),
			MakeItem("CHEM-ACETONE-M", Stack),
			MakeItem("CHEM-AMMONIA-M", Stack),
			MakeItem("CHEM-METHANOL-S", Stack),
			MakeItem("CHEM-EPHE", Stack),
			MakeItem("CHEM-PHENYL", Stack),
			MakeItem("CHEM-CH3COOH", Stack),
			MakeItem("CHEM-ACETONE-L", Stack),
			MakeItem("CHEM-AMMONIA-L", Stack),
			MakeItem("CHEM-METHANOL-L", Stack),
			MakeItem("CHEM-HI", Stack)
		};
		inline std::array<SDK::FInventoryObjectData, 5> Meds
		{
			MakeItem("MED-BANDAGE", Stack),
			MakeItem("MED-AID-KIT", Stack),
			MakeItem("MED-ANTIVENOM", Stack),
			MakeItem("MED-COUGH", Stack),
			MakeItem("MED-MIGRAINE", Stack)
		};
		inline std::array<SDK::FInventoryObjectData, 21> Cloths
		{
			MakeItem("CLOTH-BALACLAVA", Stack),
			MakeItem("CLOTH-HAT", Stack),
			MakeItem("CLOTH-CAP", Stack),
			MakeItem("CLOTH-TSHIRT", Stack),
			MakeItem("CLOTH-TANKTOP", Stack),
			MakeItem("CLOTH-SWEATSHIRT-01", Stack),
			MakeItem("CLOTH-ELEGANT-SHIRT", Stack),
			MakeItem("CLOTH-PANTS-02", Stack),
			MakeItem("CLOTH-SPORT-PANTS", Stack),
			MakeItem("CLOTH-ELEGANT-PANTS", Stack),
			MakeItem("CLOTH-SNEAKERS-01", Stack),
			MakeItem("CLOTH-ELEGANT-SHOES", Stack),
			MakeItem("CLOTH-FANNYPACK", Stack),
			MakeItem("CLOTH-BACKPACK-S", Stack),
			MakeItem("CLOTH-BACKPACK-L", Stack),
			MakeItem("CLOTH-BACKPACK-M", Stack),
			MakeItem("CLOTH-FIELD-BOOTS", Stack),
			MakeItem("CLOTH-MILI-JACKET", Stack),
			MakeItem("CLOTH-MILI-PANTS", Stack),
			MakeItem("CLOTH-MILI-SHOES", Stack),
			MakeItem("CLOTH-MILI-CAP", Stack)
		};
		inline std::array<SDK::FInventoryObjectData, 21> Random
		{
			MakeItem("MONEY-LOCAL-LARGE", Stack),
			MakeItem("MONEY-LOCAL-SMALL", Stack),
			MakeItem("DRINK-BEER", Stack),
			MakeItem("FOOD-CHOCO-BAR", Stack),
			MakeItem("FOOD-CACAO-S", Stack),
			MakeItem("JEWEL-DOG-TAG", Stack),
			MakeItem("JEWEL-WATCH", Stack),
			MakeItem("JEWEL-BRACELET", Stack),
			MakeItem("JEWEL-SUNGLASSES-01", Stack),
			MakeItem("JEWEL-NECKLACE-01", Stack),
			MakeItem("PLANT-IND-SEED", Stack),
			MakeItem("PLANT-SAT-SEED", Stack),
			MakeItem("PLANT-POPPY", Stack),
			MakeItem("PLANT-IND-SAP-M", Stack),
			MakeItem("PLANT-IND-SAP-F", Stack),
			MakeItem("PLANT-SAT-SAP-F", Stack),
			MakeItem("PLANT-SAT-SAP-M", Stack),
			MakeItem("DRUG-BLUNT", Stack),
			MakeItem("DRUG-COOKIE", Stack),
			MakeItem("PLANT-SAT-FLOWER", Stack),
			MakeItem("PLANT-IND-FLOWER", Stack)
		};
	}

	namespace TP
	{
		inline char Buffer[16];
		inline std::vector<SDK::FVector> Locations{};
		inline bool SaveLocation = false;
		inline bool DeleteLocation = false;
		inline bool Teleport = false;
		inline bool TeleportFromSave = false;
		inline bool TeleportDefault = false;
		inline bool SaveName = false;
		inline bool InputPos = false;
		inline SDK::FVector CurrentPosForInput{};
		inline SDK::FVector PosForTP{};
		inline Vec3 PlayerPos{};
		inline std::vector<std::string> locNames{};
		inline int locations_id{};

		inline std::array<LocationStruct, 13> LocationsArray{
			makeLocation(SDK::FVector{128241, 14617.2, 1378.25}, "Small Island"),
			makeLocation(SDK::FVector{142853, -34405.4 ,2054.38}, "Archipelago 1"),
			makeLocation(SDK::FVector{118345, -25387.6, 1903.45}, "Archipelago 2"),
			makeLocation(SDK::FVector{140227, 19504, 3220.15}, "Bunker"),
			makeLocation(SDK::FVector{64258.7, -39251.4, 2826.2}, "Callejon"),
			makeLocation(SDK::FVector{14781.3, -6527.23, 2405.15}, "Slavs Bay"),
			makeLocation(SDK::FVector{47235.3, -56102.4, 3794.97}, "Jungle"),
			makeLocation(SDK::FVector{33821.2, 34975.5, 2970.15}, "Paraiso Peninsular"),
			makeLocation(SDK::FVector{-29187.3, -50674.1, 5853.35}, "La Colina Sangrienta"),
			makeLocation(SDK::FVector{-42529.7, -55401.2, 1954.19}, "Volcano Island"),
			makeLocation(SDK::FVector{-38548.5, -7938.91, 1502.53}, "Dueno del Mar"),
			makeLocation(SDK::FVector{-110036, 24960.9, 1102.23}, "Bahia de Oro - Downtown"),
			makeLocation(SDK::FVector{-97024.5, 4964.27, 3058.79}, "Bahia de Oro - Favela")
		};

		inline std::vector<SDK::AActor*> MapMarkers{};
		inline std::vector<SDK::AActor*> HideoutBins{};
		inline std::vector<SDK::AActor*> Hideouts{};
		inline std::vector<SDK::AActor*> OwnedVehicles{};
		inline std::vector<SDK::AActor*> Vehicles{};

		inline std::string appDataLocalPath{};
		inline std::string filePath{};

		inline SDK::FVector LocationToTpFromSave{};
	}

	namespace Misc
	{
		inline bool TeamCheck = true;
		inline bool ShowMouse = true;
		inline bool ShowFPS = true;
		inline bool DrawCrosshair = false;
		inline float CrosshairSize = 5.f;
		inline float CrosshairThickness = 1.f;
	}

	namespace esp_Colors
	{
		inline ImColor BoxColor{ 255.f, 255.f , 255.f };
		inline ImColor Box3DColor{ 255.f, 0.f , 0.f };
		inline ImColor SnaplineColor{ 255.f, 255.f , 255.f };
		inline ImColor SkeletonColor{ 255.f, 0.f, 0.f };
		inline ImColor PoliceColor{ 0.f, 0.f, 255.f };
		inline ImColor ThugColor{ 255.f, 0.f, 0.f };
		inline ImColor FovColor{ 255.f, 255.f, 255.f };
		inline ImColor CrosshairColor{ 255.f, 0.f, 0.f };
		inline ImColor Visible{ 0.f, 255.f, 255.f };
		inline ImColor NotVisible{ 255.f, 0.f, 0.f };
	}
}

namespace Colors
{
	inline ImColor White(255.f, 255.f, 255.f);
	inline ImColor Black(0.f, 0.f, 0.f);
	inline ImColor Red(255.f, 0.f, 0.f);
	inline ImColor Green(0.f, 255.f, 0.f);
	inline ImColor Blue(0.f, 0.f, 255.f);
	inline ImColor Pink(255.f, 0.f, 255.f);
	inline ImColor Cian(0.f, 255.f, 255.f);
	inline ImColor Yellow(255.f, 255.f, 0.f);
}


