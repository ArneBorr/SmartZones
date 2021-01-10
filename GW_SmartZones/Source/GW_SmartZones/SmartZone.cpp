

#include "SmartZone.h"
#include "DrawDebugHelpers.h"
#include "NPCCharacter.h"

ASmartZone::ASmartZone()
{
	PrimaryActorTick.bCanEverTick = true;

	m_pRoleManager = CreateDefaultSubobject<URoleManager>("RoleManager");
	m_pTriggerManager = CreateDefaultSubobject<UTriggerManager>("TriggerManager");
	m_pTimeline = CreateDefaultSubobject<UTimelineSZ>("Timeline");
}

void ASmartZone::BeginPlay()
{
	Super::BeginPlay();
	m_pTriggerManager->SetSmartZone(this);
	OnActorBeginOverlap.AddDynamic(this, &ASmartZone::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ASmartZone::OnOverlapEnd);
}

void ASmartZone::Tick(float elapsedSec)
{
	Super::Tick(elapsedSec);

	if (m_IsCompleted)
		return;

	bool hasScanned = false;

	if (!m_IsActive)
	{
		m_ScanTimer += elapsedSec;

		if (m_ScanTimer >= m_ScanInterval)
		{
			FVector boxExtent{}, origin{};
			GetActorBounds(false, origin, boxExtent);
			DrawDebugBox(GetWorld(), GetActorLocation(), boxExtent, FColor::Yellow, false, 0.5f, 0, 5);

			m_ScanTimer = 0;
			if (m_pTriggerManager->IsTriggerTriggered())
			{
				if (m_pRoleManager->AssignRoles(m_pNPCsInZone))
				{
					m_IsActive = true;
					m_pTimeline->Start(m_pNPCsInZone, this);
				}
			}
		}	
	}
	else
	{
		if (!m_pTimeline->Update(this, elapsedSec))
		{
			m_IsCompleted = true;
		}
	}

	if (m_IsInDebugMode)
	{
		FVector boxExtent{}, origin{};
		GetActorBounds(false, origin, boxExtent);
		//DrawDebugBox(GetWorld(), GetActorLocation(), boxExtent, m_IsActive ? FColor::Green : FColor::Red, true, -1, 0, 5);
	}
}

void ASmartZone::OnOverlapBegin(AActor* pOverlappedActor, AActor* pOtherActor)
{
	if (pOtherActor->ActorHasTag("NPC"))
	{
		ANPCCharacter* pTemp = Cast<ANPCCharacter>(pOtherActor);
		if(pTemp)
			m_pNPCsInZone.Add(pTemp);

		if (m_IsInDebugMode)
			UE_LOG(LogTemp, Warning, TEXT("ASmartZone::OnOverlapEnd : NPC Entered"));
			
	}
}

void ASmartZone::OnOverlapEnd(AActor* pOverlappedActor, AActor* pOtherActor)
{
	if (pOtherActor->ActorHasTag("NPC"))
	{
		ANPCCharacter* pTemp = Cast<ANPCCharacter>(pOtherActor);
		if (pTemp)
			m_pNPCsInZone.Remove(pTemp);

		if (m_IsInDebugMode)
			UE_LOG(LogTemp, Warning, TEXT("ASmartZone::OnOverlapEnd : NPC Exited"));		
	}
}

void ASmartZone::UpdatePublicActors_Implementation()
{
	//Implementation that gets called, if not overriden by Blueprint class
}