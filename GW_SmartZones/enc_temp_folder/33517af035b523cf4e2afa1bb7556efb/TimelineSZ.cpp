
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
{
	m_pNPC = pNPC;
	pNPC->SetAction(pSmartZone, m_Action);
	if (m_pAnimation)
	{
		pNPC->GetMesh()->SetAnimationMode(EAnimationMode::AnimationSingleNode);
		pNPC->GetMesh()->PlayAnimation(m_pAnimation, true);
		pNPC->GetMesh()->GetSingleNodeInstance()->StopAnim();
		pNPC->GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
		
	}
	//pNPC->GetMesh()->GetSingleNodeInstance();

	GetWorld()->GetTimerManager().SetTimer(m_TimerHandle, this, &UTimelineBehaviorSZ::UpdateTimer, 1, true, 0);
}

void UTimelineBehaviorSZ::UpdateTimer()
{
	m_Timer += 1;
}

bool UTimelineBehaviorSZ::IsCompleted()
{
	switch (m_TransType)
	{
		case TransitionType::EndOfAction:
			m_pNPC->IsBehaviorCompleted();
			break;
		case TransitionType::EndOfDuration:
			UE_LOG(LogTemp, Warning, TEXT("%f"), m_Timer);
			return m_Duration <= m_Timer;
			break;
	}

	return m_pNPC->IsBehaviorCompleted();
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

bool UTimelineRowSZ::IsSequenceCompleted()
{
	return m_pActiveBehavior ?  m_pActiveBehavior->IsCompleted() : false;
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

bool UTimelineSZ::Update(class ASmartZone* pSmartZone, float elapsedSec)
{
	bool isRowCompleted = false;
	for (UTimelineRowSZ* pRow : m_pRows)
	{
		isRowCompleted |= pRow->IsSequenceCompleted();
	}

	if (isRowCompleted)
	{
		++m_CurrentSequence; 
		bool hasTimelineEnded = false;
		for (UTimelineRowSZ* pRow : m_pRows)
		{
			hasTimelineEnded |= !pRow->StartSequence(pSmartZone, m_CurrentSequence);
		}

		if (hasTimelineEnded)
		{
			return false;
		}
	}

	return true;
}

