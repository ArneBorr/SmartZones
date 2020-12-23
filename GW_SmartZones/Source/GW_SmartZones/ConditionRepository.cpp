
#include "ConditionRepository.h"
#include "SmartZone.h"

ConditionRepository::ConditionRepository()
{
	auto OneNPCInZone = [](ASmartZone* pSmartZone)->bool { return pSmartZone->GetNrOfNPCsInZone() == 1; };
	
	m_pConditions.Add(new Condition(OneNPCInZone, "MinNPC_1"));
}

Condition* ConditionRepository::GetCondition(const FString& name) const
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
