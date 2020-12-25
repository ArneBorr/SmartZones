#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TimelineSZ.generated.h"

UCLASS(BlueprintType)
class GW_SMARTZONES_API UTimelineBehaviorSZ : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		void Initialize(const FString& name, float timeStart, float timeEnd, class UAnimationAsset* pAnim = nullptr);

private:
	FString m_Name;
	class UAnimationAsset* m_pAnimation;
	float m_TimeStart;
	float m_TimeEnd;
};

UCLASS(BlueprintType)
class GW_SMARTZONES_API UTimelineRowSZ : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		void AddBehaviour(UTimelineBehaviorSZ* pBehavior) { if (pBehavior) m_pBehaviours.Add(pBehavior); };

private:
	TArray<UTimelineBehaviorSZ*> m_pBehaviours;
	FString m_Name;
};


UCLASS()
class GW_SMARTZONES_API UTimelineSZ : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		void AddRow(UTimelineRowSZ* pRow) { if (pRow) m_pRows.Add(pRow); };
private:
	TArray<UTimelineRowSZ*> m_pRows;
};
