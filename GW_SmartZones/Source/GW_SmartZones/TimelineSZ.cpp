
#include "TimelineSZ.h"
#include "Animation/AnimationAsset.h"
#include "NPCCharacter.h"
#include "RoleManager.h"
#include "SmartZone.h"
#include "Animation/AnimSingleNodeInstance.h"

//Behavior

void UTimelineBehaviorSZ::Initialize(UAnimationAsset* pAnim, const FString& name, const FString& action, TransitionType transType, float duration, int seq)
{
	m_Name = name;
	m_Action = action;
	m_TransType = transType;
	m_pAnimation = pAnim;
	m_Duration = duration;
	m_Sequence = seq;
}

void UTimelineBehaviorSZ::Execute(ANPCCharacter* pNPC, ASmartZone* pSmartZone)
{;
	pNPC->SetAction(pSmartZone, m_Action);
	if (m_pAnimation)
	{
		pNPC->GetMesh()->PlayAnimation(m_pAnimation, true);
	}

	if (m_TransType == TransitionType::EndOfDuration)
		GetWorld()->GetTimerManager().SetTimer(m_TimerHandle, this, &UTimelineBehaviorSZ::UpdateTimer, 1, true, 0);
}

void UTimelineBehaviorSZ::Exit(ANPCCharacter* pNPC)
{
	if (m_pAnimation)
	{
		pNPC->ContinueAnimBlueprint();
	}
}

void UTimelineBehaviorSZ::UpdateTimer()
{
	m_Timer += 1;
}

bool UTimelineBehaviorSZ::IsCompleted(ANPCCharacter* pNPC)
{
	switch (m_TransType)
	{
		case TransitionType::EndOfAction:
			return pNPC->IsBehaviorCompleted();
		case TransitionType::EndOfDuration:
			return m_Duration <= m_Timer;
		case TransitionType::EndOfSequence:;
			return false;
	}

	return false;
}

//Row

void UTimelineRowSZ::Initialize(const FString& name)
{
	m_Name = name;
}

void UTimelineRowSZ::AddNPC(ANPCCharacter* pNPC)
{
	m_pNPCs.Add(pNPC);
}

bool UTimelineRowSZ::StartSequence(ASmartZone* pSmartZone, int seq)
{
	m_pActiveBehavior = nullptr;
	for (UTimelineBehaviorSZ* pBeh : m_pBehaviors)
	{
		if (pBeh->GetSequence() == seq)
		{
			m_pActiveBehavior = pBeh;
			break;
		}
	}

	if (!m_pActiveBehavior)
	{
		for (ANPCCharacter* pNPC : m_pNPCs)
		{
			pNPC->SetInteracting(false);			
		}

		return false;
	}

	for (ANPCCharacter* pNPC : m_pNPCs)
	{			
			m_pActiveBehavior->Execute(pNPC, pSmartZone);
			pNPC->SetInteracting(true);	
	}

	return true;
}

void UTimelineRowSZ::StartBehaviorSingleNPC(ANPCCharacter* pNPC, ASmartZone* pSmartZone)
{
	if (m_pActiveBehavior)
	{
		m_pActiveBehavior->Execute(pNPC, pSmartZone);
		pNPC->SetInteracting(true);
	}
}

void UTimelineRowSZ::EndBehavior()
{
	if (m_pActiveBehavior)
	{
		for (ANPCCharacter* pNPC : m_pNPCs)
		{
			m_pActiveBehavior->Exit(pNPC);
		}
		
		m_pActiveBehavior = nullptr;
	}
}

bool UTimelineRowSZ::IsSequenceCompleted()
{
	bool isSequenceCompleted = false;
	if (m_pActiveBehavior)
	{	
		for (ANPCCharacter* pNPC : m_pNPCs)
		{
			isSequenceCompleted |= m_pActiveBehavior->IsCompleted(pNPC);
		}
	}

	return isSequenceCompleted;
}

//Timeline

void UTimelineSZ::Start(const TArray<ANPCCharacter*>& pNPCsInZone, ASmartZone* pSmartZone)
{
	if (m_IsActive)
		return;

	m_IsActive = true;
	
	for (UTimelineRowSZ* pRow : m_pRows)
	{
		for (ANPCCharacter* pNPC : pNPCsInZone)
		{
			if (pNPC->GetRole().Name == pRow->GetName())
				pRow->AddNPC(pNPC);
		}

		pRow->StartSequence(pSmartZone, 1);
	}
}

void UTimelineSZ::AddDynamicNPC(class ASmartZone* pSmartZone, ANPCCharacter* pNPC)
{
	for (UTimelineRowSZ* pRow : m_pRows)
	{
		if (pNPC->GetRole().Name == pRow->GetName())
		{
			pRow->AddNPC(pNPC);
			pRow->StartBehaviorSingleNPC(pNPC, pSmartZone);
		}
	}
}

bool UTimelineSZ::Update(class ASmartZone* pSmartZone, float elapsedSec)
{
	bool isSequenceCompleted = false;
	for (UTimelineRowSZ* pRow : m_pRows)
	{
		isSequenceCompleted |= pRow->IsSequenceCompleted();
	}

	if (isSequenceCompleted)
	{
		++m_CurrentSequence; 
		bool shouldTimelineContinue = false;
		for (UTimelineRowSZ* pRow : m_pRows)
		{
			pRow->EndBehavior();
			shouldTimelineContinue |= pRow->StartSequence(pSmartZone, m_CurrentSequence);
		}

		if (!shouldTimelineContinue)
		{
			return false;
		}
	}

	return true;
}

