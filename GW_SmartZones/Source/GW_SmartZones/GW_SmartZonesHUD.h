// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GW_SmartZonesHUD.generated.h"

UCLASS()
class AGW_SmartZonesHUD : public AHUD
{
	GENERATED_BODY()

public:
	AGW_SmartZonesHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

