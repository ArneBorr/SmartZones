#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ConditionRepository.generated.h"

class ASmartZone;

class GW_SMARTZONES_API Condition final
{
public:
	Condition(TFunction<bool(ASmartZone*)> f, const FString& name) : m_Function(f), m_Name(name) {};

	bool IsTrue(ASmartZone* pSmartZone)
	{
		return m_Function(pSmartZone);
	}

	const FString& GetName() const { return m_Name; }

private:
	TFunction<bool(ASmartZone*)> m_Function;
	FString m_Name;
};

UCLASS(BlueprintType)
class GW_SMARTZONES_API UConditionRepository final : public UObject
{
GENERATED_BODY()
public:
	UConditionRepository();

	Condition* GetCondition(const FString& name) const;

private:
	TArray<Condition*> m_pConditions;
};
