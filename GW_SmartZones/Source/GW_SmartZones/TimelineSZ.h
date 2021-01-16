#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TimelineSZ.generated.h"

UENUM(BlueprintType)
enum TransitionType
{
	EndOfSequence,   
	EndOfAction,
	EndOfDuration
};

UCLASS(BlueprintType)
class GW_SMARTZONES_API UTimelineBehaviorSZ : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		void Initialize(class UAnimationAsset* pAnim, const FString& name, const FString& action, TransitionType transType, float duration, int seq);

	void Execute(class ANPCCharacter* pNPC, class ASmartZone* pSmartZone);
	void Exit(class ANPCCharacter* pNPC);
	bool IsCompleted(class ANPCCharacter* pNPC);

	int GetSequence() const { return m_Sequence; };
private:
	FString m_Name;
	FString m_Action;
	FTimerHandle m_TimerHandle;
	class UAnimationAsset* m_pAnimation = nullptr;
	TransitionType m_TransType;
	float m_Duration;
	float m_Timer = 0;
	int m_Sequence;

	void UpdateTimer();
};

UCLASS(BlueprintType)
class GW_SMARTZONES_API UTimelineRowSZ : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		void Initialize(const FString& name);
	UFUNCTION(BlueprintCallable)
		void AddBehaviour(UTimelineBehaviorSZ* pBehavior) { if (pBehavior) m_pBehaviors.Add(pBehavior); };

	void AddNPC(class ANPCCharacter* pNPC);
	bool StartSequence(class ASmartZone* pSmartZone, int seq);
	void StartBehaviorSingleNPC(class ANPCCharacter* pNPC, class ASmartZone* pSmartZone);
	void EndBehavior();
	bool IsSequenceCompleted();
	const FString& GetName() { return m_Name; };

private:
	TArray<UTimelineBehaviorSZ*> m_pBehaviors;
	TArray<ANPCCharacter*> m_pNPCs;
	UTimelineBehaviorSZ* m_pActiveBehavior;
	FString m_Name;
};


UCLASS()
class GW_SMARTZONES_API UTimelineSZ : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		void AddRow(UTimelineRowSZ* pRow) { if (pRow) m_pRows.Add(pRow); };

	void Start(const TArray<class ANPCCharacter*>& pNPCsInZone, class ASmartZone* pSmartZone);
	void AddDynamicNPC(class ASmartZone* pSmartZone, class ANPCCharacter* pNPC);
	bool Update(class ASmartZone* pSmartZone, float elapsedSec);
private:
	TArray<UTimelineRowSZ*> m_pRows;
	
	unsigned int m_CurrentSequence = 1;
	bool m_IsActive = false;
};
