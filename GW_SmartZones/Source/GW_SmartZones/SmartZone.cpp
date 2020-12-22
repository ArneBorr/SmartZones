

#include "SmartZone.h"
#include "DrawDebugHelpers.h"

ASmartZone::ASmartZone()
{
	
	//OnActorEndOverlap.AddDynamic(this, &ASmartZone::OnOverlapEnd);
}

void ASmartZone::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ASmartZone::OnOverlapBegin);
	if (m_IsInDebugMode)
	{
		FVector boxExtent{}, origin{};
		GetActorBounds(false, origin, boxExtent);
		DrawDebugBox(GetWorld(), GetActorLocation(), boxExtent, FColor::Purple, true, -1, 0, 5);
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
