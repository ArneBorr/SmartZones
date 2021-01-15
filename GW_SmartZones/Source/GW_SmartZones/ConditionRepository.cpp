
#include "ConditionRepository.h"
#include "SmartZone.h"

UConditionRepository::UConditionRepository()
{
	std::function<bool(ASmartZone* pSmartZone)> OneNPCInZone = [](ASmartZone* pSmartZone)->bool { return pSmartZone->GetNrOfNPCsInZone() >= 1; };
	std::function<bool(ASmartZone* pSmartZone)> TwoNPCInZone = [](ASmartZone* pSmartZone)->bool { return pSmartZone->GetNrOfNPCsInZone() >= 2; };
	
	m_pConditions.Add(new Condition(OneNPCInZone, "MinNPC_1"));
	m_pConditions.Add(new Condition(TwoNPCInZone, "MinNPC_2"));
}

Condition* UConditionRepository::GetCondition(const FString& name) const
{
	for (Condition* pCondition : m_pConditions)
	{
		if (pCondition->GetName() == name)
		{
			return pCondition;
		}
	}

	return nullptr;
}

bool Condition::IsTrue(ASmartZone* pSmartZone)
{
	bool isTrue = false;
	
	if (pSmartZone)
		isTrue = m_Function(pSmartZone);

	return isTrue;
}
