#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "SmartZone.generated.h"

UCLASS()
class GW_SMARTZONES_API ASmartZone final : public ATriggerBox
{
	GENERATED_BODY()
public:
	void BeginPlay() override; 

	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

private:

	TArray<AActor*> m_pNPCsInZone;

	UPROPERTY(EditAnywhere, Category = "General", DisplayName = "Debug Mode", meta = (AllowPrivateAccess = true))
		bool m_IsInDebugMode = false;
};
