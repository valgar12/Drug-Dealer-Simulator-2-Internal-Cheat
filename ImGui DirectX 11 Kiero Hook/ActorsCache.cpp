#include "ActorsCache.h"
#include "SDK.hpp"

void ActorsCache::ActorsCache()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	while (alive)
	{
		while (CheatRunning)
		{
			std::this_thread::sleep_for(std::chrono::nanoseconds(1));
		}

		CacheRunning = true;

		gl::TP::MapMarkers.clear();
		gl::TP::MapMarkersPartys.clear();
		gl::TP::MapMarkersShops.clear();
		gl::TP::HideoutBins.clear();
		gl::TP::IntelligenbceSpot.clear();
		gl::TP::BusStops.clear();
		gl::TP::Parkings.clear();
		gl::TP::ClientsSpawnPoints.clear();
		gl::TP::DealersSpots.clear();
		gl::TP::Hideouts.clear();
		gl::TP::HideoutsOwned.clear();
		gl::TP::OwnedVehicles.clear();
		gl::TP::Vehicles.clear();

		actors = World->PersistentLevel->Actors;

		for (int i = 0; i < actors.Num(); i++)
		{
			if (i >= actors.Num()) break;

			if (!actors[i]) continue;

			SDK::AActor* actor = actors[i];

			if (!actor->RootComponent) continue;
			if (actor->RootComponent->RelativeLocation.IsZero()) continue;

			if (actor->GetName().find("MapMarker") != std::string::npos)
			{
				auto MapMarker = reinterpret_cast<SDK::ABP_WorldLocationMapMarker_C*>(actor);

				if (MapMarker->StaticLocationID.ToString()[0] == 'S' && MapMarker->StaticLocationID.ToString().find("SHOP-") != std::string::npos)
				{
					gl::TP::MapMarkersShops.push_back(actor);
					continue;
				}
				else if (MapMarker->StaticLocationID.ToString()[0] == 'P' && MapMarker->StaticLocationID.ToString().find("PARTY-") != std::string::npos)
				{
					gl::TP::MapMarkersPartys.push_back(actor);
					continue;
				}
				else
				{
					gl::TP::MapMarkers.push_back(actor);
				}
				
				continue;
			}
			if (actor->GetName().find("Intelligence") != std::string::npos)
			{
				gl::TP::IntelligenbceSpot.push_back(actor);
				continue;
			}
			if (actor->GetName().find("ClientSpawnPoint") != std::string::npos)
			{
				gl::TP::ClientsSpawnPoints.push_back(actor);
				continue;
			}
			if (actor->GetName().find("Parking") != std::string::npos)
			{
				gl::TP::Parkings.push_back(actor);
				continue;
			}
			if (actor->GetName().find("BusStop") != std::string::npos)
			{
				gl::TP::BusStops.push_back(actor);
				continue;
			}
			if (actor->GetName().find("Dealer") != std::string::npos)
			{
				gl::TP::DealersSpots.push_back(actor);
				continue;
			}
			if (actor->GetName().find("HideoutTrash") != std::string::npos)
			{
				gl::TP::HideoutBins.push_back(actor);
				continue;
			}
			if (actor->GetName().find("HideoutMaster") != std::string::npos)
			{
				auto HideoutClass = reinterpret_cast<SDK::ABP_HideoutMaster_C*>(actor);

				if (HideoutClass->HideoutOwned)
					gl::TP::HideoutsOwned.push_back(actor);
				else
					gl::TP::Hideouts.push_back(actor);

				continue;
			}
			if (actor->GetName().find("Veh") != std::string::npos)
			{
				auto Vehicle = reinterpret_cast<SDK::AQuickTravelOwnedVehicle_C*>(actor);

				if (Vehicle->CarOwned)
				{
					gl::TP::OwnedVehicles.push_back(actor);
				}
				else
					gl::TP::Vehicles.push_back(actor);
				continue;
			}
		}

		CacheRunning = false;

		std::this_thread::sleep_for(std::chrono::seconds(30));
	}
}