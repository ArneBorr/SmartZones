// Copyright Epic Games, Inc. All Rights Reserved.

#include "GW_SmartZonesGameMode.h"
#include "GW_SmartZonesHUD.h"
#include "GW_SmartZonesCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGW_SmartZonesGameMode::AGW_SmartZonesGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGW_SmartZonesHUD::StaticClass();
}
