
#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ConditionRepository.h"
#include "TriggerManager.generated.h"

UCLASS(BlueprintType)
class GW_SMARTZONES_API UTrigger : public UObject
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	void AddCondition(UConditionRepository* pRepo, const FString& name)
	{ 
		if (pRepo)
		{
			Condition* pCondition = pRepo->GetCondition(name);
			if (pCondition) m_pConditions.Add(pCondition);
		}
	};

private:
	TArray<Condition*> m_pConditions;
};

UCLASS()
class GW_SMARTZONES_API UTriggerManager : public UObject
{
	GENERATED_BODY()
		
	UFUNCTION(BlueprintCallable)
		void AddTrigger(UTrigger* pTrigger);

private:
	TArray<UTrigger*> m_pTriggers;
};
