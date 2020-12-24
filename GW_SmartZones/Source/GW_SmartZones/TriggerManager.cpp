
#include "TriggerManager.h"

void UTriggerManager::AddTrigger(UTrigger* pTrigger)
{
	if (pTrigger)
		m_pTriggers.Add(pTrigger);
}
