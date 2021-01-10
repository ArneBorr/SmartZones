#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "RoleManager.h"
#include "TriggerManager.h"
#include "TimelineSZ.h"
#include "SmartZone.generated.h"


UCLASS()
class GW_SMARTZONES_API ASmartZone final : public ATriggerBox
{
	GENERATED_BODY()
public:
	ASmartZone();
	void BeginPlay() override; 
	void Tick(float elapsedSec) override;

	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION(CallInEditor, BlueprintNativeEvent, Category = "General", DisplayName = "Update Public Variables")
		void UpdatePublicActors();


	int GetNrOfNPCsInZone() const { return m_pNPCsInZone.Num(); }

private:
	TArray<class ANPCCharacter*> m_pNPCsInZone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General", DisplayName = "Role Manager", meta = (AllowPrivateAccess = true))
		URoleManager* m_pRoleManager;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General", DisplayName = "Trigger Manager", meta = (AllowPrivateAccess = true))
		UTriggerManager* m_pTriggerManager;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General", DisplayName = "Time Line", meta = (AllowPrivateAccess = true))
		UTimelineSZ* m_pTimeline;

	UPROPERTY(EditAnywhere, Category = "General", DisplayName = "Debug Mode", meta = (AllowPrivateAccess = true))
		float m_ScanInterval = false;

	float m_Timer = 0;

	UPROPERTY(EditAnywhere, Category = "General", DisplayName = "Debug Mode", meta = (AllowPrivateAccess = true))
		bool m_IsInDebugMode = false;

	bool m_IsActive = false;;
	bool m_IsCompleted = false;
};
