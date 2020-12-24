
#include "TriggerManager.h"
#include "SmartZone.h"

//Trigger

bool UTrigger::IsTriggered(ASmartZone* pSmartZone) const
{
	for (Condition* pCon : m_pConditions)
	{
		if (pCon->IsTrue(pSmartZone))
			return true;
	}

	return false;
}

//Trigger Manager

bool UTriggerManager::IsTriggerTriggered() const
{
	for (UTrigger* pTrigger : m_pTriggers)
	{
		if (pTrigger->IsTriggered(m_pSmartZone))
			return true;
	}

	return false;
}

void UTriggerManager::SetSmartZone(ASmartZone* pSmartZone)
{
	m_pSmartZone = pSmartZone;
}

void UTriggerManager::AddTrigger(UTrigger* pTrigger)
{
	if (pTrigger)
		m_pTriggers.Add(pTrigger);
}
