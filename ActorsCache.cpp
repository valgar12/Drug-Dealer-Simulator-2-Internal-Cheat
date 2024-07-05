#include "ActorsCache.h"
#include "SDK.hpp"

void ActorsCache::ActorsCache()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	while (alive)
	{
		gl::TP::MapMarkers.clear();
		gl::TP::HideoutBins.clear();
		gl::TP::Hideouts.clear();
		gl::TP::OwnedVehicles.clear();
		gl::TP::Vehicles.clear();

		actors = World->PersistentLevel->Actors;

		for (int i = 0; i < actors.Num(); i++)
		{
			if (i >= actors.Num()) break;

			if (!actors[i]) continue;

			SDK::AActor* actor = actors[i];

			if (actor->GetName().find("MapMarker") != std::string::npos)
			{
				gl::TP::MapMarkers.push_back(actor);
				continue;
			}
			if (actor->GetName().find("HideoutTrash") != std::string::npos)
			{
				gl::TP::HideoutBins.push_back(actor);
				continue;
			}
			if (actor->GetName().find("HideoutMaster") != std::string::npos)
			{
				gl::TP::Hideouts.push_back(actor);
				continue;
			}
			if (actor->GetName().find("Veh") != std::string::npos)
			{
				auto Vehicle = reinterpret_cast<SDK::AQuickTravelOwnedVehicle_C*>(actor);

				gl::TP::Vehicles.push_back(actor);

				if (Vehicle->CarOwned)
				{
					gl::TP::OwnedVehicles.push_back(actor);
				}
				continue;
			}
		}

		std::this_thread::sleep_for(std::chrono::seconds(30));
	}
}