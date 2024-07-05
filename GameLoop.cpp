#include "GameLoop.h"
#include "SDK.hpp"

void GameLoop()
{
	if (PlayerList.size() > 0)
	{
		float MaxDistance = FLT_MAX;
		bool IsActorVisibleAim = false;
		SDK::AActor* closest_actor{};
		SDK::FRotator closest_actor_rotation{};

		for (int i = 0; i < PlayerList.size(); i++)
		{
			if (i > PlayerList.size()) break;

			SDK::AActor* actor = PlayerList[i];

			auto ActorState = actor->Instigator->PlayerState;

			if (!MyController->PlayerCameraManager) continue;

			auto CameraLocation = MyController->PlayerCameraManager->GetCameraLocation();
			auto CameraRotation = MyController->PlayerCameraManager->GetCameraRotation();

			auto LocalController = reinterpret_cast<ABP_DDS2_PlayerController_C*>(MyController);
			auto LocalCharacter = reinterpret_cast<ABP_PlayerCharacter_C*>(MyController->Character);

			if (!LocalCharacter->BP_ConsoleCommandsComponent) continue;

			auto ConsoleComponnent = LocalCharacter->BP_ConsoleCommandsComponent;

			auto LocalPos = LocalCharacter->K2_GetActorLocation();

			if (gl::TP::SaveLocation)
			{
				gl::TP::locNames.push_back(gl::TP::Buffer);
				if (gl::TP::Buffer && gl::TP::Buffer[0])
					gl::TP::Locations.push_back(LocalPos);
				gl::TP::SaveName = false;
				gl::TP::SaveLocation = false;

				Locations::Location loc{};
				loc.name = gl::TP::Buffer;
				loc.x = LocalPos.X;
				loc.y = LocalPos.Y;
				loc.z = LocalPos.Z;

				Locations::writeLocationToFile(gl::TP::filePath, loc);
			}
			if (gl::TP::DeleteLocation)
			{
				Locations::Location loc{};

				for (int l = 0; l < Locations::LocationsReaded.size(); l++)
				{
					if (Locations::LocationsReaded[l].name == gl::TP::Buffer)
					{
						loc = Locations::LocationsReaded[l];
						Locations::LocationsReaded.erase(Locations::LocationsReaded.begin() + l);
						break;
					}
				}

				Locations::deleteLocationFromFile(gl::TP::filePath, gl::TP::Buffer);

				for (int l = 0; l < gl::TP::locNames.size(); l++)
				{
					if (gl::TP::locNames[l] == gl::TP::Buffer)
					{
						gl::TP::locNames.erase(gl::TP::locNames.begin() + l);
						gl::TP::Locations.erase(gl::TP::Locations.begin() + l);
						break;
					}	
				}

				gl::TP::DeleteLocation = false;
			}
			if (gl::TP::Teleport)
			{
				LocalCharacter->K2_TeleportTo(gl::TP::Locations[gl::TP::locations_id], LocalCharacter->K2_GetActorRotation());
				gl::TP::Teleport = false;
			}
			if (gl::TP::TeleportFromSave)
			{
				LocalCharacter->K2_TeleportTo(gl::TP::LocationToTpFromSave, LocalCharacter->K2_GetActorRotation());
				gl::TP::TeleportFromSave = false;
			}
			if (gl::TP::TeleportDefault)
			{
				LocalCharacter->K2_TeleportTo(gl::TP::PosForTP + SDK::FVector(0, 0, 100), LocalCharacter->K2_GetActorRotation());
				gl::TP::TeleportDefault = false;
			}	

			SDK::AActor* MyActor{};

			if (ActorState == MyController->PlayerState)
			{
				MyActor = actor;
			}

			if (ActorState == MyController->PlayerState) continue;

			if (!actor) continue;
			if (!actor->Instigator) continue;
			if (!actor->Instigator->Controller) continue;
			if (!actor->Instigator->Controller->Character) continue;
			if (!actor->Instigator->Controller->Character->Mesh) continue;

			auto mesh = actor->Instigator->Controller->Character->Mesh;
			if (!mesh) continue;

			SDK::FVector location = actor->K2_GetActorLocation();

			float ActorDistance = LocalPos.GetDistanceToInMeters(location);

			bool IsActorVisible = false;

			SDK::FVector head_bone_pos = mesh->GetSocketLocation(mesh->GetBoneName(9));
			SDK::FVector feet_bone_pos = mesh->GetSocketLocation(mesh->GetBoneName(132));
			SDK::FVector torso_bone_pos = mesh->GetSocketLocation(mesh->GetBoneName(7));

			SDK::FVector feet_middle_pos = { location.X, location.Y, feet_bone_pos.Z };

			SDK::FVector2D Bottom{};
			SDK::FVector2D Top{};
			SDK::FVector2D Middle{};

			//Exploits-------------------------------------------------------------------------------

			auto CharacterMovement = LocalCharacter->CharacterMovement;

			if (!LocalCharacter->BP_InventoryComponent) continue;

			auto InventoryComponent = LocalCharacter->BP_InventoryComponent;

			if (!InventoryComponent->RepQuickSlots) continue;

			auto QuickSlots = InventoryComponent->RepQuickSlots;

			if (gl::Exploits::InfiniteStamina)
			{
				if (LocalCharacter->StaminaLevel < 100)
					LocalCharacter->StaminaLevel = 100;
			}
			if (gl::Exploits::SuperSpeed)
			{
				LocalCharacter->SprintMaxSpeed = 3000;
			}
			if (gl::Exploits::FastSwim)
			{
				CharacterMovement->MaxSwimSpeed = 5000.f;
			}
			if (gl::Exploits::FastFly)
			{
				CharacterMovement->MaxFlySpeed = 5000.f;
			}
			if (gl::Exploits::FastAcceleration)
			{
				CharacterMovement->MaxAcceleration = 5000.f;
			}
			if (gl::Exploits::GodMode)
			{
				if (LocalCharacter->PlayerCurHealth < 1000000)
					LocalCharacter->PlayerCurHealth = 1000000;
			}
			if (gl::Exploits::SuperJump)
			{
				if (GetAsyncKeyState(VK_SPACE) & 1)
				{
					SDK::FVector Pos = LocalCharacter->K2_GetActorLocation();
					Pos += SDK::FVector{ 0.f, 0.f, 250.f };

					LocalCharacter->K2_TeleportTo(Pos, LocalCharacter->K2_GetActorRotation());
				}
			}
			if (gl::Exploits::cheats::GiveMoneyInventory)
			{

				SDK::FString Status{TEXT(L"0")};
				UC::int32 LeftOver{};

				InventoryComponent->AddNewItem(StrToName("MONEY-LOCAL-LARGE"), 400000, false, Status, &LeftOver);	

				gl::Exploits::cheats::GiveMoneyInventory = false;
			}
			if (gl::Exploits::cheats::GiveMoneyBank)
			{
				ConsoleComponnent->GiveBankMoney(static_cast<double>(1000000));

				gl::Exploits::cheats::GiveMoneyBank = false;
			}
			if (gl::Exploits::cheats::GiveAllFurtniture)
			{
				ConsoleComponnent->GiveAllFurniture(10);
				gl::Exploits::cheats::GiveAllFurtniture = false;
			}
			if (gl::Exploits::cheats::GiveAllSubstances)
			{
				ConsoleComponnent->AddAllSubstances(1000);
				gl::Exploits::cheats::GiveAllSubstances = false;
			}
			if (gl::Exploits::cheats::GhostMode || GetAsyncKeyState(VK_F1) & 1)
			{

				ConsoleComponnent->ServerToggleGhost();

				if (MyController->AcknowledgedPawn->bActorEnableCollision == 1)
					MyController->AcknowledgedPawn->bActorEnableCollision = 0;
				else
					MyController->AcknowledgedPawn->bActorEnableCollision = 1;
				
				
				gl::Exploits::cheats::GhostMode = false;
			}
			if (gl::Exploits::cheats::ClearMapFog)
			{
				ConsoleComponnent->MapFogClear();
				gl::Exploits::cheats::ClearMapFog = false;
			}
			if (gl::Exploits::cheats::ResetMapFog)
			{
				ConsoleComponnent->MapFogReset();
				gl::Exploits::cheats::ResetMapFog = false;
			}
			if (gl::Exploits::cheats::MaxShopsReputation)
			{
				ConsoleComponnent->AddAllShopsReputation(1000000);
				gl::Exploits::cheats::MaxShopsReputation = false;
			}
			if (gl::Exploits::cheats::RestockShops)
			{
				ConsoleComponnent->ServerRestockAllShops();
				ConsoleComponnent->ServerResetAllShopsBuyLimit();
				gl::Exploits::cheats::RestockShops = false;
			}
			if (gl::Exploits::cheats::UnlockAllShopOffers)
			{
				ConsoleComponnent->ServerUnlockAllShopOffers();
				gl::Exploits::cheats::UnlockAllShopOffers = false;
			}
			if (gl::Exploits::cheats::UnlockAllHideouts)
			{
				ConsoleComponnent->ServerUnlockAllHideouts();
				gl::Exploits::cheats::UnlockAllHideouts = false;
			}
			if (gl::Exploits::cheats::GiveCartelXP)
			{
				ConsoleComponnent->ServerAddCartelXP(10000000);
				gl::Exploits::cheats::GiveCartelXP = false;
			}
			if (gl::Exploits::cheats::GiveStreetCreed)
			{
				ConsoleComponnent->ServerChangeSteetCred(1000000);
				gl::Exploits::cheats::GiveStreetCreed = false;
			}
			if (gl::Exploits::cheats::SetTime)
			{
				ConsoleComponnent->ServerCheatSetTime(gl::Exploits::cheats::hour);
				gl::Exploits::cheats::SetTime = false;
			}
			if (gl::Exploits::cheats::SkipDay)
			{
				ConsoleComponnent->ServerCheatSetTime(24);
				gl::Exploits::cheats::SkipDay = false;
			}
			if (gl::Exploits::cheats::CleanTrashBins)
			{
				if (gl::TP::HideoutBins.size() > 0)
				{
					for (int l = 0; l < gl::TP::HideoutBins.size(); l++)
					{
						if (!gl::TP::HideoutBins[l]) continue;

						auto Bin = reinterpret_cast<SDK::ABP_HideoutTrashBin_C*>(gl::TP::HideoutBins[l]);

						Bin->WasteTotal = 0;
						Bin->WastePresent = false;
					}
				}
				if (gl::TP::Hideouts.size() > 0)
				{
					for (int l = 0; l < gl::TP::Hideouts.size(); l++)
					{
						if (!gl::TP::Hideouts[l]) continue;

						auto Hideout = reinterpret_cast<SDK::ABP_HideoutMaster_C*>(gl::TP::Hideouts[l]);

						if (Hideout->HideoutOwned == false) continue;

						Hideout->RemoveSubstance(StrToName("WASTE"), 1.f, true);
					}
				}


				gl::Exploits::cheats::CleanTrashBins = false;
			}
			//------------------------------------------------------
			if (gl::Exploits::FastMeleeAtack)
			{
				LocalCharacter->AttackSpeedMultiplier = 10;
			}
			if (gl::Exploits::SuperFlashlight)
			{
				LocalCharacter->FlashlightPower = gl::Exploits::FlashPower;
				LocalCharacter->FlashlightRadius = gl::Exploits::FlashRange;
			}
			if (gl::Exploits::NoWeight)
			{
				LocalCharacter->WeightSpeedClamp = 100;
				InventoryComponent->RepInventoryWeight = 0.1f;
			}
			if (gl::Exploits::UnbreakingWeapons)
			{
				for (int l = 0; l < QuickSlots.Num(); l++)
				{
					if (QuickSlots[l].ObjectData.CurHealth < 3000)
						QuickSlots[l].ObjectData.CurHealth = 3000;
				}
			}
			if (gl::Items::SpawnItem)
			{
				SDK::FString Status{ TEXT(L"0") };
				UC::int32 LeftOver{};

				UC::int32 IdOverride{ 0 };

				for (int l = 0; l < InventoryComponent->RepInventoryGrid.Num(); l++)
				{
					if (InventoryComponent->RepInventoryGrid[l].ObjectData.SubstanceContents.SubstanceID
						== gl::Items::CurrentItemToSpawn.SubstanceContents.SubstanceID && InventoryComponent->RepInventoryGrid[l].ObjectData.SubstanceContents.GramAmount == 1.f
						&& gl::Items::CurrentItemToSpawn.SubstanceContents.GramAmount == 1.f &&
						InventoryComponent->RepInventoryGrid[l].ObjectData.CurStack < 40 &&
						InventoryComponent->RepInventoryGrid[l].ObjectData.CurStack + gl::Items::Stack <= 40)
					{
						IdOverride = l;
						break;
					}

					if (InventoryComponent->RepInventoryGrid[l].ObjectData.CurStack <= 0)
					{
						IdOverride = l;
						break;
					}
				}

				InventoryComponent->AddSpecificItem(gl::Items::CurrentItemToSpawn, false, &LeftOver, gl::Items::Stack, IdOverride);

				gl::Items::SpawnItem = false;
			}
			if (gl::Exploits::InfiniteFuel)
			{
				if (gl::TP::OwnedVehicles.size() > 0)
				{
					for (int l = 0; l < gl::TP::OwnedVehicles.size(); l++)
					{
						if (l >= gl::TP::OwnedVehicles.size()) break;
						if (!gl::TP::OwnedVehicles[l]) continue;

						auto Vehicle = reinterpret_cast<SDK::AQuickTravelOwnedVehicle_C*>(gl::TP::OwnedVehicles[l]);

						if (Vehicle->VehicleCurFuel < Vehicle->VehicleMaxFuel)
						{
							Vehicle->VehicleCurFuel = Vehicle->VehicleMaxFuel;
						}
					}
				}
			}

			if (MyController->ProjectWorldLocationToScreen(feet_middle_pos, &Bottom, false)
				&& MyController->ProjectWorldLocationToScreen(head_bone_pos, &Top, false)
				 && MyController->ProjectWorldLocationToScreen(location, &Middle, false))
			{
				const float h = std::abs(Top.Y - Bottom.Y);
				const float w = h * 0.2f;

				if (gl::ESP::VisCheck)
				{
					if (MyController->LineOfSightTo(actor, MyController->PlayerCameraManager->CameraCachePrivate.POV.Location, false))
					{
						IsActorVisible = true;
					}
				}
				

				if (gl::World::World)
				{
					if (gl::World::Boats)
					{
						if (actor->GetName().find("Boat") != std::string::npos)
						{
							auto Vehicle = reinterpret_cast<SDK::AQuickTravelOwnedVehicle_C*>(actor);

							if (Vehicle->CarOwned)
							{
								ESP::DrawText2(Vec2(Middle.X, Middle.Y), Colors::White, "Boat");
								continue;
							}
							continue;
						}
					}
					if (gl::World::Vehicles)
					{
						if (actor->GetName().find("Veh") != std::string::npos)
						{
							auto Vehicle = reinterpret_cast<SDK::AQuickTravelOwnedVehicle_C*>(actor);
							if (!Vehicle) continue;

							if (Vehicle->CarOwned)
							{
								if (actor->GetName().find("Bike") != std::string::npos)
								{
									ESP::DrawText2(Vec2(Middle.X, Middle.Y), Colors::White, "Bike");
									continue;
								}
								else if (actor->GetName().find("Boat") != std::string::npos)
								{
			
								}
								else
								{
									ESP::DrawText2(Vec2(Middle.X, Middle.Y), Colors::White, "Car");
									continue;
								}
							}
							
							continue;
						}
					}
					if (gl::World::Influencers)
					{
						if (actor->GetName().find("Influ") != std::string::npos)
						{
							std::string InfluencerName = GetInfluencerName(actor->GetName());
							std::string WordToShow = "Influencer " + InfluencerName;

							ESP::DrawText2(Vec2(Middle.X, Middle.Y), Colors::White, WordToShow.c_str());
							continue;
						}
					}
				}

				if (gl::ESP::ESP)
				{
					if (actor->GetName().find("Police") == std::string::npos
						&& actor->GetName().find("Thug") == std::string::npos) continue;

					auto OponnentClass = reinterpret_cast<SDK::ABP_NPC_OponentBase_C*>(actor);

					if (OponnentClass->CurHealth <= 0) continue;

					if (!gl::ESP::Police)
					{
						if (actor->GetName().find("Police") != std::string::npos) continue;
					}
					if (!gl::ESP::Thugs)
					{
						if (actor->GetName().find("Thug") != std::string::npos) continue;
					}

					if (gl::ESP::ESP_Skeleton)
					{
						if (!IsActorVisible)
						{
							if (actor->GetName().find("Police") != std::string::npos)
							{
								DrawBones(mesh, MyController, gl::esp_Colors::PoliceColor);
							}
							else if (actor->GetName().find("Thug") != std::string::npos)
							{
								DrawBones(mesh, MyController, gl::esp_Colors::ThugColor);
							}
						}
						else
							DrawBones(mesh, MyController, gl::esp_Colors::Visible);
					}
					if (gl::ESP::ESP_Box)
					{
						if (!IsActorVisible)
						{
							if (actor->GetName().find("Police") != std::string::npos)
							{
								ESP::DrawBox(Vec2(Top.X - w, Top.Y), Vec2(Bottom.X + w, Bottom.Y), gl::esp_Colors::PoliceColor, true);
							}
							else if (actor->GetName().find("Thug") != std::string::npos)
							{
								ESP::DrawBox(Vec2(Top.X - w, Top.Y), Vec2(Bottom.X + w, Bottom.Y), gl::esp_Colors::ThugColor, true);
							}
						}
						else
							ESP::DrawBox(Vec2(Top.X - w, Top.Y), Vec2(Bottom.X + w, Bottom.Y), gl::esp_Colors::Visible, true);
					}
					if (gl::ESP::ESP_Snaplines)
					{
						if (!IsActorVisible)
							ESP::DrawLine(Vec2(1920 / 2, 0), Vec2(Top.X, Top.Y), gl::esp_Colors::SnaplineColor);
						else
							ESP::DrawLine(Vec2(1920 / 2, 0), Vec2(Top.X, Top.Y), gl::esp_Colors::Visible);
					}
					if (gl::ESP::ESP_Names)
					{
						if (actor->GetName().find("Police") != std::string::npos)
						{
							ESP::DrawText2(Vec2(Middle.X, Middle.Y), gl::esp_Colors::PoliceColor, "Police");
						}
						else
						{
							ESP::DrawText2(Vec2(Middle.X, Middle.Y), gl::esp_Colors::ThugColor, "Thug");
						}
						//ESP::DrawText2(Vec2(Top.X - w, Top.Y - 15), Colors::White, actor->GetName().c_str());
					}
					if (gl::ESP::HealthBar)
					{

						if (OponnentClass->CurHealth <= 100)
						{
							ESP::DrawBoxFilled(Vec2(Top.X - w - 6, Top.Y - 1), Vec2(Top.X - w - 3, Bottom.Y + 1), Colors::Black);
							ESP::DrawBoxFilled(Vec2(Top.X - w - 5, Bottom.Y - (h * (OponnentClass->CurHealth * 0.01))), Vec2(Top.X - w - 4, Bottom.Y), Colors::Green);
						}
					}
				}
				
				if (gl::Aimbot::Aimbot)
				{
					if (gl::Aimbot::ShowFov)
					{
						ESP::DrawCircle(Vec2(1920 / 2, 1080 / 2), gl::Aimbot::Fov, gl::esp_Colors::FovColor, 80);
					}

					FVector2D Torso_Bone{};
					if (MyController->ProjectWorldLocationToScreen(torso_bone_pos, &Torso_Bone, false))
					{
						auto rot = UKismetMathLibrary::FindLookAtRotation(CameraLocation, torso_bone_pos);

						FVector2D screen_middle = { 1920 / 2, 1080 / 2 };

						aimbot_distance = UKismetMathLibrary::Distance2D(Torso_Bone, screen_middle);

						if (aimbot_distance < MaxDistance && aimbot_distance <= gl::Aimbot::Fov)
						{
							MaxDistance = aimbot_distance;
							closest_actor = actor;
							closest_actor_rotation = rot;

							if (gl::ESP::VisCheck)
							{
								if (IsActorVisible)
									IsActorVisibleAim = true;
								else
									IsActorVisibleAim = false;
							}
						}
					}
				}
			}
		}
		if (closest_actor && gl::Aimbot::Aimbot && GetAsyncKeyState(VK_XBUTTON2))
		{
			if (gl::ESP::VisCheck)
			{
				if (IsActorVisibleAim)
					MyController->SetControlRotation(closest_actor_rotation);
			}
			else
				MyController->SetControlRotation(closest_actor_rotation);
		}
	}
}