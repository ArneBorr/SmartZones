// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SmartZoneRepository.generated.h"

UCLASS()
class GW_SMARTZONES_API ASmartZoneRepository : public AActor
{
	GENERATED_BODY()
	
public:	
	ASmartZoneRepository();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(CallInEditor, BlueprintNativeEvent, Category = "General", DisplayName = "Load XMLFile")
		void LoadFile();
protected:
	virtual void BeginPlay() override;

};
