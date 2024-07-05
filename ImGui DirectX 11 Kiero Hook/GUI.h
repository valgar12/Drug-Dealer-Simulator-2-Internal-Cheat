#pragma once
#include "includes.h"
#include "functions.h"

inline void DrawMenu()
{
	ImGui::Begin("Valgar1 Base");

	if (ImGui::BeginTabBar("tabs"))
	{
		if (ImGui::BeginTabItem("Visuals"))
		{
			ImGui::Checkbox("ESP", &gl::ESP::ESP);
			if (gl::ESP::ESP)
			{
				ImGui::Separator();
				ImGui::Checkbox("Vischeck", &gl::ESP::VisCheck);
				ImGui::Separator();
				ImGui::Checkbox("Box", &gl::ESP::ESP_Box);
				
				
				ImGui::Checkbox("Snaplines", &gl::ESP::ESP_Snaplines);
				if (gl::ESP::ESP_Snaplines)
				{
					ImGui::SameLine();
					ImGui::ColorEdit3("##Snaplines color", (float*)&gl::esp_Colors::SnaplineColor, ImGuiColorEditFlags_NoInputs);
				}

				ImGui::Checkbox("Skeleton", &gl::ESP::ESP_Skeleton);
				ImGui::Checkbox("Health Bar", &gl::ESP::HealthBar);
				ImGui::Checkbox("Names", &gl::ESP::ESP_Names);
				
				ImGui::Separator();
				ImGui::Checkbox("Police", &gl::ESP::Police);
				if (gl::ESP::Police)
				{
					ImGui::SameLine();
					ImGui::ColorEdit3("##Police color", (float*)&gl::esp_Colors::PoliceColor, ImGuiColorEditFlags_NoInputs);
				}
				ImGui::Checkbox("Thugs", &gl::ESP::Thugs);
				if (gl::ESP::Thugs)
				{
					ImGui::SameLine();
					ImGui::ColorEdit3("##Thugs color", (float*)&gl::esp_Colors::ThugColor, ImGuiColorEditFlags_NoInputs);
				}
			}

			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("World"))
		{
			ImGui::Text("WORLD ESP");
			ImGui::Separator();
			ImGui::Checkbox("World ESP", &gl::World::World);
			ImGui::Checkbox("Vehicles", &gl::World::Vehicles);
			ImGui::Checkbox("Boats", &gl::World::Boats);
			//ImGui::Checkbox("Shops", &gl::World::Shops);
			ImGui::Checkbox("Influencers", &gl::World::Influencers);

			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Aimbot"))
		{
			ImGui::Checkbox("Aimbot", &gl::Aimbot::Aimbot);
			if (gl::Aimbot::Aimbot)
			{
				ImGui::Separator();
				ImGui::SliderFloat("FOV", &gl::Aimbot::Fov, 5.f, 3000.f);
				ImGui::Checkbox("Show FOV", &gl::Aimbot::ShowFov);
				ImGui::SameLine();
				ImGui::ColorEdit3("##FOV color", (float*)&gl::esp_Colors::FovColor, ImGuiColorEditFlags_NoInputs);
				ImGui::SliderFloat("Smooth", &gl::Aimbot::Smooth, 0.f, 10.f);
			}

			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Exploits"))
		{
			ImGui::Checkbox("Unlimited Stamina", &gl::Exploits::InfiniteStamina);
			ImGui::Checkbox("Super Speed", &gl::Exploits::SuperSpeed);
			ImGui::Checkbox("Fast swim", &gl::Exploits::FastSwim);
			ImGui::Checkbox("Fast fly", &gl::Exploits::FastFly);
			ImGui::Checkbox("Fast Acceleration", &gl::Exploits::FastAcceleration);
			ImGui::Checkbox("Super Jump", &gl::Exploits::SuperJump);
			ImGui::Checkbox("God Mode", &gl::Exploits::GodMode);
			ImGui::Checkbox("No break weapoons", &gl::Exploits::UnbreakingWeapons);
			ImGui::Checkbox("No Weight", &gl::Exploits::NoWeight);
			ImGui::Checkbox("Fast Melee Atack", &gl::Exploits::FastMeleeAtack);
			ImGui::Checkbox("Infinite Fuel", &gl::Exploits::InfiniteFuel);
			ImGui::Checkbox("Super Flashlight", &gl::Exploits::SuperFlashlight);
			if (gl::Exploits::SuperFlashlight)
			{
				ImGui::SliderInt("Light Power", &gl::Exploits::FlashPower, 10, 1000);
				ImGui::SliderInt("Light Range", &gl::Exploits::FlashRange, 10, 1000);
			}
			ImGui::Separator();
			ImGui::SliderInt("Hour", &gl::Exploits::cheats::hour, 1, 24);
			if (ImGui::Button("Set Time", ImVec2(150, 30)))
			{
				gl::Exploits::cheats::SetTime = true;
			}
			ImGui::SameLine();
			if (ImGui::Button("Make Day", ImVec2(150, 30)))
			{
				gl::Exploits::cheats::hour = 8;
				gl::Exploits::cheats::SetTime = true;
			}
			ImGui::SameLine();
			if (ImGui::Button("Make Night", ImVec2(150, 30)))
			{
				gl::Exploits::cheats::hour = 22;
				gl::Exploits::cheats::SetTime = true;
			}
			ImGui::SameLine();
			if (ImGui::Button("Skip Day", ImVec2(150, 30)))
			{
				gl::Exploits::cheats::SkipDay = true;
			}
			ImGui::Separator();
			if (ImGui::Button("Give Money Bank", ImVec2(150, 30)))
			{
				gl::Exploits::cheats::GiveMoneyBank = true;
			}
			ImGui::SameLine();
			if (ImGui::Button("Give Money Inventory", ImVec2(150, 30)))
			{
				gl::Exploits::cheats::GiveMoneyInventory = true;
			}
			ImGui::SameLine();
			if (ImGui::Button("Clear Map Fog", ImVec2(150, 30)))
			{
				gl::Exploits::cheats::ClearMapFog = true;
			}
			if (ImGui::Button("Reset Map Fog", ImVec2(150, 30)))
			{
				gl::Exploits::cheats::ResetMapFog = true;
			}
			ImGui::SameLine();
			if (ImGui::Button("Restock All Shops", ImVec2(150, 30)))
			{
				gl::Exploits::cheats::RestockShops = true;
			}
			ImGui::SameLine();
			if (ImGui::Button("Unlock All Shops Offers", ImVec2(200, 30)))
			{
				gl::Exploits::cheats::UnlockAllShopOffers = true;
			}
			if (ImGui::Button("Max Shops Reputation", ImVec2(200, 30)))
			{
				gl::Exploits::cheats::MaxShopsReputation = true;
			}
			ImGui::SameLine();
			if (ImGui::Button("Unlock All Hideouts", ImVec2(150, 30)))
			{
				gl::Exploits::cheats::UnlockAllHideouts = true;
			}
			ImGui::SameLine();
			if (ImGui::Button("Toggle Fly/Noclip [F1]", ImVec2(160, 30)))
			{
				gl::Exploits::cheats::GhostMode = true;
			}
			if (ImGui::Button("Give all furtniture", ImVec2(150, 30)))
			{
				gl::Exploits::cheats::GiveAllFurtniture = true;
			}
			ImGui::SameLine();
			if (ImGui::Button("Give all substances", ImVec2(150, 30)))
			{
				gl::Exploits::cheats::GiveAllSubstances = true;
			}
			ImGui::SameLine();
			if (ImGui::Button("Max Cartel XP", ImVec2(150, 30)))
			{
				gl::Exploits::cheats::GiveCartelXP = true;
			}
			if (ImGui::Button("Max Street Creed", ImVec2(150, 30)))
			{
				gl::Exploits::cheats::GiveStreetCreed = true;
			}
			if (ImGui::Button("Clean All Hideouts Bins", ImVec2(280, 30)))
			{
				gl::Exploits::cheats::CleanTrashBins = true;
			}

			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Items"))
		{
			ImGui::SliderInt("Quantity", &gl::Items::Stack, 1, 100);
			ImGui::SliderInt("Grams", &gl::Items::GramAmountInt, 1, 400);
			ImGui::Separator();
			ImGui::Text("DRUGS");
			ImGui::Separator();
			for (int i = 0; i < gl::Items::Drugs.size(); i++)
			{
				if (i % 3 != 0)
					ImGui::SameLine();

				if (ImGui::Button(gl::Items::Drugs[i].SubstanceContents.SubstanceID.ToString().c_str(), ImVec2(220, 30)))
				{
					gl::Items::CurrentItemToSpawn = gl::Items::Drugs[i];
					gl::Items::CurrentItemToSpawn.CurStack = gl::Items::Stack;
					gl::Items::CurrentItemToSpawn.ItemId = gl::Items::Drugs[i].ItemId;
					gl::Items::CurrentItemToSpawn.SubstanceContents.SubstanceID = gl::Items::Drugs[i].SubstanceContents.SubstanceID;
					gl::Items::CurrentItemToSpawn.SubstanceContents.GramAmount = static_cast<float>(gl::Items::GramAmountInt);

					gl::Items::SpawnItem = true;
				}
			}
			ImGui::Separator();
			ImGui::Text("Tools");
			ImGui::Separator();
			for (int i = 0; i < gl::Items::Tools.size(); i++)
			{
				if (i % 3 != 0)
					ImGui::SameLine();

				if (ImGui::Button(gl::Items::Tools[i].ItemId.ToString().c_str(), ImVec2(250, 30)))
				{
					gl::Items::CurrentItemToSpawn = gl::Items::Tools[i];
					gl::Items::CurrentItemToSpawn.CurStack = gl::Items::Stack;
					gl::Items::CurrentItemToSpawn.ItemId = gl::Items::Tools[i].ItemId;
					gl::Items::CurrentItemToSpawn.CurUsesLeft = 1100;
					gl::Items::CurrentItemToSpawn.CurHealth = 3000;

					gl::Items::SpawnItem = true;
				}
			}
			ImGui::Separator();
			ImGui::Text("Items");
			ImGui::Separator();
			for (int i = 0; i < gl::Items::Items.size(); i++)
			{
				if (i % 3 != 0)
					ImGui::SameLine();

				if (ImGui::Button(gl::Items::Items[i].ItemId.ToString().c_str(), ImVec2(250, 30)))
				{
					gl::Items::CurrentItemToSpawn = gl::Items::Items[i];
					gl::Items::CurrentItemToSpawn.CurStack = gl::Items::Stack;
					gl::Items::CurrentItemToSpawn.ItemId = gl::Items::Items[i].ItemId;
					/*gl::Items::CurrentItemToSpawn.CurUsesLeft = 1100;
					gl::Items::CurrentItemToSpawn.CurHealth = 3000;*/
					//gl::Items::CurrentItemToSpawn.SubstanceContents.GramAmount = 5000.f;

					if (gl::Items::CurrentItemToSpawn.ItemId.ToString() == "ITEM-FLOUR-M")
					{
						gl::Items::CurrentItemToSpawn.SubstanceContents.GramAmount = 1000;
						gl::Items::CurrentItemToSpawn.SubstanceContents.SubstanceID = StrToName("SUBSTANCE-FLOUR");
					}
					if (gl::Items::CurrentItemToSpawn.ItemId.ToString() == "ITEM-SUGAR-M")
					{
						gl::Items::CurrentItemToSpawn.SubstanceContents.GramAmount = 1000;
						gl::Items::CurrentItemToSpawn.SubstanceContents.SubstanceID = StrToName("SUBSTANCE-SUGAR");
					}
					if (gl::Items::CurrentItemToSpawn.ItemId.ToString() == "ITEM-SALT-M")
					{
						gl::Items::CurrentItemToSpawn.SubstanceContents.GramAmount = 1000;
						gl::Items::CurrentItemToSpawn.SubstanceContents.SubstanceID = StrToName("SUBSTANCE-SALT");
					}
					if (gl::Items::CurrentItemToSpawn.ItemId.ToString() == "ITEM-FERTILIZER-SYN-M")
					{
						gl::Items::CurrentItemToSpawn.SubstanceContents.GramAmount = 3000;
						gl::Items::CurrentItemToSpawn.SubstanceContents.SubstanceID = StrToName("SUBSTANCE-FERTILIZER-SYN");
					}
					if (gl::Items::CurrentItemToSpawn.ItemId.ToString() == "ITEM-TABACCO-PACK")
					{
						gl::Items::CurrentItemToSpawn.SubstanceContents.GramAmount = 50;
						gl::Items::CurrentItemToSpawn.SubstanceContents.SubstanceID = StrToName("SUBSTANCE-TABACCO");
					}
					if (gl::Items::CurrentItemToSpawn.ItemId.ToString() == "ITEM-FERTILIZER-M")
					{
						gl::Items::CurrentItemToSpawn.SubstanceContents.GramAmount = 1000;
						gl::Items::CurrentItemToSpawn.SubstanceContents.SubstanceID = StrToName("SUBSTANCE-FERTILIZER");
					}
					if (gl::Items::CurrentItemToSpawn.ItemId.ToString() == "ITEM-FERTILIZER-L")
					{
						gl::Items::CurrentItemToSpawn.SubstanceContents.GramAmount = 5000;
						gl::Items::CurrentItemToSpawn.SubstanceContents.SubstanceID = StrToName("SUBSTANCE-FERTILIZER");
					}

					gl::Items::SpawnItem = true;
				}
			}
			ImGui::Separator();
			ImGui::Text("Chems");
			ImGui::Separator();
			for (int i = 0; i < gl::Items::Chems.size(); i++)
			{
				if (i % 3 != 0)
					ImGui::SameLine();

				if (ImGui::Button(gl::Items::Chems[i].ItemId.ToString().c_str(), ImVec2(250, 30)))
				{
					gl::Items::CurrentItemToSpawn = gl::Items::Chems[i];
					gl::Items::CurrentItemToSpawn.CurStack = gl::Items::Stack;
					gl::Items::CurrentItemToSpawn.ItemId = gl::Items::Chems[i].ItemId;
					gl::Items::CurrentItemToSpawn.CurUsesLeft = 1100;
					gl::Items::CurrentItemToSpawn.CurHealth = 3000;

					gl::Items::SpawnItem = true;
				}
			}
			ImGui::Separator();
			ImGui::Text("Meds");
			ImGui::Separator();
			for (int i = 0; i < gl::Items::Meds.size(); i++)
			{
				if (i % 3 != 0)
					ImGui::SameLine();

				if (ImGui::Button(gl::Items::Meds[i].ItemId.ToString().c_str(), ImVec2(250, 30)))
				{
					gl::Items::CurrentItemToSpawn = gl::Items::Meds[i];
					gl::Items::CurrentItemToSpawn.CurStack = gl::Items::Stack;
					gl::Items::CurrentItemToSpawn.ItemId = gl::Items::Meds[i].ItemId;
					gl::Items::CurrentItemToSpawn.CurUsesLeft = 1100;
					gl::Items::CurrentItemToSpawn.CurHealth = 3000;

					gl::Items::SpawnItem = true;
				}
			}
			ImGui::Separator();
			ImGui::Text("Cloths");
			ImGui::Separator();
			for (int i = 0; i < gl::Items::Cloths.size(); i++)
			{
				if (i % 3 != 0)
					ImGui::SameLine();

				if (ImGui::Button(gl::Items::Cloths[i].ItemId.ToString().c_str(), ImVec2(250, 30)))
				{
					gl::Items::CurrentItemToSpawn = gl::Items::Cloths[i];
					gl::Items::CurrentItemToSpawn.CurStack = gl::Items::Stack;
					gl::Items::CurrentItemToSpawn.ItemId = gl::Items::Cloths[i].ItemId;
					gl::Items::CurrentItemToSpawn.CurUsesLeft = 1100;
					gl::Items::CurrentItemToSpawn.CurHealth = 3000;

					gl::Items::SpawnItem = true;
				}
			}
			ImGui::Separator();
			ImGui::Text("Random");
			ImGui::Separator();
			for (int i = 0; i < gl::Items::Random.size(); i++)
			{
				if (i % 3 != 0)
					ImGui::SameLine();

				if (ImGui::Button(gl::Items::Random[i].ItemId.ToString().c_str(), ImVec2(250, 30)))
				{
					gl::Items::CurrentItemToSpawn = gl::Items::Random[i];
					gl::Items::CurrentItemToSpawn.CurStack = gl::Items::Stack;
					gl::Items::CurrentItemToSpawn.ItemId = gl::Items::Random[i].ItemId;
					gl::Items::CurrentItemToSpawn.CurUsesLeft = 1100;
					gl::Items::CurrentItemToSpawn.CurHealth = 3000;

					if (gl::Items::CurrentItemToSpawn.ItemId.ToString() == "FOOD-CACAO-S")
					{
						gl::Items::CurrentItemToSpawn.SubstanceContents.GramAmount = 500;
						gl::Items::CurrentItemToSpawn.SubstanceContents.SubstanceID = StrToName("SUBSTANCE-CACAO");
					}

					gl::Items::SpawnItem = true;
				}
			}

			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Teleport"))
		{
			/*if (ImGui::Button("Input Pos", ImVec2(100, 30)))
			{
				gl::TP::InputPos = true;
			}*/

			ImGui::InputText("Location Name", gl::TP::Buffer, 16);
			if (ImGui::Button("Save Location", ImVec2(100, 30)))
			{
				gl::TP::SaveLocation = true;
			}
			ImGui::SameLine();
			if (ImGui::Button("Delete Location", ImVec2(120, 30)))
			{
				gl::TP::DeleteLocation = true;
			}

			ImGui::Separator();
			ImGui::Text("Custom TP");
			ImGui::Separator();

			if (Locations::LocationsReaded.size() > 0)
			{
				for (int i = 0; i < Locations::LocationsReaded.size(); i++)
				{
					if (ImGui::Button(Locations::LocationsReaded[i].name.c_str(), ImVec2(80, 30)))
					{
						gl::TP::LocationToTpFromSave.X = Locations::LocationsReaded[i].x;
						gl::TP::LocationToTpFromSave.Y = Locations::LocationsReaded[i].y;
						gl::TP::LocationToTpFromSave.Z = Locations::LocationsReaded[i].z;

						gl::TP::TeleportFromSave = true;
					}
					if (i + 1 != Locations::LocationsReaded.size()) ImGui::SameLine();
				}
			}

			if (gl::TP::Locations.size() > 0 && gl::TP::locNames.size() > 0 && gl::TP::Locations.size() == gl::TP::locNames.size())
			{
				for (int i = 0; i < gl::TP::Locations.size(); i++)
				{
					if (ImGui::Button(gl::TP::locNames[i].c_str(), ImVec2(80, 30)))
					{
						gl::TP::locations_id = i;
						gl::TP::Teleport = true;
					}
					if (i + 1 != gl::TP::Locations.size()) ImGui::SameLine();
				}
			}

			ImGui::Separator();
			ImGui::Text("Default TPS");
			ImGui::Separator();
			
			for (int i = 0; i < gl::TP::LocationsArray.size(); i++)
			{
				if (i % 4 != 0)
				{
					ImGui::SameLine();
				}
					

				if (ImGui::Button(gl::TP::LocationsArray[i].Name.c_str(), ImVec2(170, 30)))
				{
					gl::TP::PosForTP = gl::TP::LocationsArray[i].Pos;
					gl::TP::TeleportDefault = true;
				}
			}

			ImGui::Separator();
			ImGui::Text("Map Markers");
			ImGui::Separator();

			if (gl::TP::MapMarkers.size() > 0)
			{
				for (int i = 0; i < gl::TP::MapMarkers.size(); i++)
				{
					if (i % 7 != 0)
					{
						ImGui::SameLine();
					}

					if (gl::TP::MapMarkers[i])
					{
						auto MapMarker = reinterpret_cast<SDK::ABP_WorldLocationMapMarker_C*>(gl::TP::MapMarkers[i]);

						if (ImGui::Button(MapMarker->StaticLocationID.ToString().c_str(), ImVec2(170, 30)))
						{
							gl::TP::PosForTP = gl::TP::MapMarkers[i]->K2_GetActorLocation();
							gl::TP::TeleportDefault = true;
						}
					}
				}
			}
			ImGui::Separator();
			ImGui::Text("Vehicles");
			ImGui::Separator();
			if (gl::TP::OwnedVehicles.size() > 0)
			{
				for (int i = 0; i < gl::TP::OwnedVehicles.size(); i++)
				{
					if (i % 3 != 0)
					{
						ImGui::SameLine();
					}

					std::string VehicleName{};

					if (gl::TP::OwnedVehicles[i]->GetName().find("Boat") != std::string::npos)
					{
						VehicleName = "Boat";
					}
					else if ((gl::TP::OwnedVehicles[i]->GetName().find("Bike") != std::string::npos))
					{
						VehicleName = "Bike";
					}
					else
					{
						VehicleName = "Car";
					}

					if (ImGui::Button(VehicleName.c_str(), ImVec2(120, 30)))
					{
						gl::TP::PosForTP = gl::TP::OwnedVehicles[i]->K2_GetActorLocation();
						gl::TP::TeleportDefault = true;
					}
				}
			}
			ImGui::Separator();
			ImGui::Text("Hideouts Owned");
			ImGui::Separator();
			if (gl::TP::Hideouts.size() > 0)
			{
				for (int i = 0; i < gl::TP::Hideouts.size(); i++)
				{
					if (i % 2 != 0)
					{
						ImGui::SameLine();
					}

					auto Hideout = reinterpret_cast<SDK::ABP_HideoutMaster_C*>(gl::TP::Hideouts[i]);

					if (Hideout->HideoutOwned == false) continue;

					if (ImGui::Button(Hideout->HideoutID.ToString().c_str(), ImVec2(170, 30)))
					{
						gl::TP::PosForTP = gl::TP::Hideouts[i]->K2_GetActorLocation();
						gl::TP::TeleportDefault = true;
					}
				}
			}
			ImGui::Separator();
			ImGui::Text("Hideouts All");
			ImGui::Separator();
			if (gl::TP::Hideouts.size() > 0)
			{
				for (int i = 0; i < gl::TP::Hideouts.size(); i++)
				{
					if (i % 7 != 0)
					{
						ImGui::SameLine();
					}

					auto Hideout = reinterpret_cast<SDK::ABP_HideoutMaster_C*>(gl::TP::Hideouts[i]);

					if (ImGui::Button(Hideout->HideoutID.ToString().c_str(), ImVec2(170, 30)))
					{
						gl::TP::PosForTP = gl::TP::Hideouts[i]->K2_GetActorLocation();
						gl::TP::TeleportDefault = true;
					}
				}
			}

			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Misc"))
		{
			ImGui::Checkbox("Show mouse", &gl::Misc::ShowMouse);
			ImGui::Checkbox("Show FPS", &gl::Misc::ShowFPS);
			ImGui::Checkbox("Crosshair", &gl::Misc::DrawCrosshair);
			if (gl::Misc::DrawCrosshair)
			{
				ImGui::SameLine();
				ImGui::ColorEdit3("##Crosshair color", (float*)&gl::esp_Colors::CrosshairColor, ImGuiColorEditFlags_NoInputs);
				ImGui::SliderFloat("Crosshair Size", &gl::Misc::CrosshairSize, 1.f, 20.f);
				ImGui::SliderFloat("Crosshair Thickness", &gl::Misc::CrosshairThickness, 1.f, 5.f);
			}
			ImGui::EndTabItem();
		}

		ImGui::EndTabBar();
	}

	ImGui::End();
}

inline void SetColorsFlags()
{
	ImVec4* colors = ImGui::GetStyle().Colors;

	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.88f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.11f, 0.11f, 0.14f, 0.92f);
	colors[ImGuiCol_Border] = ImVec4(1.00f, 1.00f, 1.00f, 0.50f);
	colors[ImGuiCol_BorderShadow] = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.35f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.88f, 0.88f, 0.90f, 0.40f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.53f, 0.53f, 0.53f, 0.69f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.23f, 0.23f, 0.23f, 0.83f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.65f, 0.65f, 0.65f, 0.87f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.47f, 0.47f, 0.47f, 0.20f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.43f, 0.43f, 0.43f, 0.80f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.25f, 0.30f, 0.60f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.71f, 0.71f, 0.71f, 0.30f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.40f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
	colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.50f, 0.50f, 0.50f, 0.60f);
	colors[ImGuiCol_Button] = ImVec4(1.00f, 1.00f, 1.00f, 0.57f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.79f);
	colors[ImGuiCol_ButtonActive] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.40f, 0.40f, 0.40f, 0.45f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.45f, 0.45f, 0.90f, 0.80f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.53f, 0.53f, 0.87f, 0.80f);
	colors[ImGuiCol_Separator] = ImVec4(0.50f, 0.50f, 0.50f, 0.60f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.60f, 0.60f, 0.70f, 1.00f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.70f, 0.70f, 0.90f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.16f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.78f, 0.82f, 1.00f, 0.60f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.78f, 0.82f, 1.00f, 0.90f);
	colors[ImGuiCol_Tab] = ImVec4(0.42f, 0.42f, 0.42f, 0.79f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.76f, 0.76f, 0.76f, 0.80f);
	colors[ImGuiCol_TabActive] = ImVec4(0.81f, 0.81f, 0.81f, 0.84f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.28f, 0.28f, 0.57f, 0.82f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.35f, 0.35f, 0.65f, 0.84f);
	colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	colors[ImGuiCol_NavHighlight] = ImVec4(0.45f, 0.45f, 0.90f, 0.80f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);



	ImGuiStyle& style = ImGui::GetStyle();

	style.FrameBorderSize = 1.f;
	style.TabBorderSize = 1.f;
	style.WindowTitleAlign.x = 0.50f;
	style.WindowPadding = ImVec2(5, 5);
	style.WindowRounding = 12.0f;
	style.FramePadding = ImVec2(6, 6);
	style.FrameRounding = 2.0f;
	style.ItemSpacing = ImVec2(12, 8);
	style.ItemInnerSpacing = ImVec2(8, 6);
	style.IndentSpacing = 25.0f;
	style.ScrollbarSize = 15.0f;
	style.ScrollbarRounding = 9.0f;
	style.GrabMinSize = 20.0f;
	style.GrabRounding = 3.0f;
	style.TabRounding = 8.f;
}
