#include "SmartZoneRepository.h"

ASmartZoneRepository::ASmartZoneRepository()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ASmartZoneRepository::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASmartZoneRepository::LoadFile_Implementation()
{
	//Implementation that gets called, if not overriden by Blueprint class
}

void ASmartZoneRepository::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

