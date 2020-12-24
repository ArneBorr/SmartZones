#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "RoleManager.h"
#include "TriggerManager.h"
#include "SmartZone.generated.h"


UCLASS()
class GW_SMARTZONES_API ASmartZone final : public ATriggerBox
{
	GENERATED_BODY()
public:
	ASmartZone();
	void BeginPlay() override; 

	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	int GetNrOfNPCsInZone() const { return m_pNPCsInZone.Num(); }

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General", DisplayName = "Role Manager", meta = (AllowPrivateAccess = true))
		URoleManager* m_pRoleManager;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General", DisplayName = "Trigger Manager", meta = (AllowPrivateAccess = true))
		UTriggerManager* m_pTriggerManager;
	TArray<AActor*> m_pNPCsInZone;

	UPROPERTY(EditAnywhere, Category = "General", DisplayName = "Debug Mode", meta = (AllowPrivateAccess = true))
		bool m_IsInDebugMode = false;
};
