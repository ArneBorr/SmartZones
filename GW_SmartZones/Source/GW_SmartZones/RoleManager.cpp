
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
			if (!AssignRandomRole(pNPCs[i], false))
				return false;
		}
	}

	//Return false when not all roles have their min cardinality achieved

	for (int i{ currentIndex }; i < m_Roles.Num(); i++)
	{
		if (m_Roles[i].CardinalityMin > m_Roles[i].CurrentNrOfNPCsWithThisRole)
			return false;
	}

	return true;
}

bool URoleManager::AssignRandomRole(ANPCCharacter* pNPC, bool isDynamic)
{
	int currentIndex = FMath::RandRange(0, m_Roles.Num() - 1);
	FRole& currentRole = m_Roles[currentIndex];

	unsigned int tries = 0;

	
	auto getRandomRole = [&tries, &currentIndex,  &currentRole ,this]()
	{
		currentIndex = FMath::RandRange(0, m_Roles.Num() - 1);
		currentRole = m_Roles[currentIndex];
	};

	while (currentRole.CardinalityMax <= currentRole.CurrentNrOfNPCsWithThisRole && (isDynamic ? !currentRole.CanJoinDynamically : true))
	{
		getRandomRole();
		++tries;
		if (tries > 20)
			return false;
	}
	

	pNPC->SetRole(currentRole);
	pNPC->SetInteracting(true);
	return true;
}
