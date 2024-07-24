#include "ActorsCacheFast.h"
#include "SDK.hpp"

void ActorsCacheFast::ActorsCacheFast()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	while (alive)
	{
		while (CheatRunning)
		{
			std::this_thread::sleep_for(std::chrono::nanoseconds(1));
		}

		FastCacheRunning = true;

		gl::TP::DropBags.clear();
		gl::TP::Clients.clear();
		gl::TP::WorkSpots.clear();
		gl::TP::Random.clear();

		actors = World->PersistentLevel->Actors;

		for (int i = 0; i < actors.Num(); i++)
		{
			if (i >= actors.Num()) break;

			if (!actors[i]) continue;

			SDK::AActor* actor = actors[i];

		/*	if (!actor->RootComponent) continue;
			if (actor->RootComponent->RelativeLocation.IsZero()) continue;*/

			if (actor->GetName().find("DropBag") != std::string::npos)
			{
				gl::TP::DropBags.push_back(actor);
				continue;
			}
			if (actor->GetName().find("BodyMaster") != std::string::npos)
			{
				gl::TP::Clients.push_back(actor);
				continue;
			}
			if (actor->GetName().find("ClientSpot") != std::string::npos)
			{
				gl::TP::WorkSpots.push_back(actor);
				continue;
			}
			
		}

		FastCacheRunning = false;

		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	}
}