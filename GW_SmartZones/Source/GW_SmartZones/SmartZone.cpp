

#include "SmartZone.h"
#include "DrawDebugHelpers.h"

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

	if (m_IsInDebugMode)
	{
		FVector boxExtent{}, origin{};
		GetActorBounds(false, origin, boxExtent);
		DrawDebugBox(GetWorld(), GetActorLocation(), boxExtent, FColor::Purple, true, -1, 0, 5);
	}
}

void ASmartZone::Tick(float elapsedSec)
{
	Super::Tick(elapsedSec);
	
	if (m_pTriggerManager->IsTriggerTriggered())
	{
		UE_LOG(LogTemp, Warning, TEXT("YUUUUUUP"));
	}
}

void ASmartZone::OnOverlapBegin(AActor* pOverlappedActor, AActor* pOtherActor)
{
	if (pOtherActor->ActorHasTag("NPC"))
	{
		m_pNPCsInZone.Add(pOtherActor);

		if (m_IsInDebugMode)
			UE_LOG(LogTemp, Warning, TEXT("ASmartZone::OnOverlapEnd : NPC Entered"));
			
	}
}

void ASmartZone::OnOverlapEnd(AActor* pOverlappedActor, AActor* pOtherActor)
{
	if (pOtherActor->ActorHasTag("NPC"))
	{
		m_pNPCsInZone.Remove(pOtherActor);

		if (m_IsInDebugMode)
			UE_LOG(LogTemp, Warning, TEXT("ASmartZone::OnOverlapEnd : NPC Exited"));		
	}
}
