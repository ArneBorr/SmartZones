
#include "RoleManager.h"
#include "NPCCharacter.h"

void URoleManager::AddRole(const FRole& role)
{
	FRole rrole;
	rrole.Name = role.Name;
	rrole.CardinalityMin = role.CardinalityMin;
	rrole.CardinalityMax = role.CardinalityMax;
	rrole.CanJoinDynamically = role.CanJoinDynamically;
	
	m_Roles.Add(rrole);
}

bool URoleManager::AssignRoles(const TArray<ANPCCharacter*>& pNPCs)
{
	bool m_MinimumAssigned = false;
	int currentIndex = 0;
	FRole& currentRole = m_Roles[currentIndex];
	for (int i{}; i < pNPCs.Num(); i++)
	{
		// First assign roles so that the minimum cardinality has been reached for each role
		if (!m_MinimumAssigned)
		{
			bool skipAssignment = false;;
			while (m_Roles[currentIndex].CardinalityMin <= m_Roles[currentIndex].CurrentNrOfNPCsWithThisRole)
			{
				++currentIndex;
				if (currentIndex >= m_Roles.Num())
				{
					m_MinimumAssigned = true;
					skipAssignment = true;
					--i;
					break;
				}	

				currentRole = m_Roles[currentIndex];
			}

			if (!skipAssignment)
			{
				pNPCs[i]->SetRole(currentRole);
				pNPCs[i]->SetInteracting(true);
				++currentRole.CurrentNrOfNPCsWithThisRole;
			}								
		}
		// Assign random roles to NPCs when min Cardinality has been reached
		else
		{
			if (!AssignRandomRole(pNPCs[i]))
				return false;
		}
	}

	//Return false when not all roles have their min cardinality achieved
	if (currentIndex < m_Roles.Num() - 1 || m_Roles.Last().CardinalityMin > m_Roles.Last().CurrentNrOfNPCsWithThisRole)
	{
		return false;
	}

	return true;
}

bool URoleManager::AssignRandomRole(ANPCCharacter* pNPC)
{
	int currentIndex = FMath::RandRange(0, m_Roles.Num() - 1);
	FRole& currentRole = m_Roles[currentIndex];

	unsigned int tries = 0;
	while (currentRole.CardinalityMax <= currentRole.CurrentNrOfNPCsWithThisRole)
	{
		currentIndex = FMath::RandRange(0, m_Roles.Num() - 1);
		currentRole = m_Roles[currentIndex];
		++tries;
		if (tries > 20)
		{
			return false;
		}
	}

	pNPC->SetRole(currentRole);
	pNPC->SetInteracting(true);
	return true;
}