
#include "RoleManager.h"

void URoleManager::AddRole(const FRole& role)
{
	FRole rrole;
	rrole.Name = role.Name;
	rrole.CardinalityMin = role.CardinalityMin;
	rrole.CardinalityMax = role.CardinalityMax;
	rrole.CanJoinDynamically = role.CanJoinDynamically;
	
	m_Roles.Add(rrole);
}
