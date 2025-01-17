
#include "NPCCharacter.h"
#include "TimelineSZ.h"

ANPCCharacter::ANPCCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ANPCCharacter::BeginPlay()
{
	Super::BeginPlay();
	m_Role.Name = "None";
}

void ANPCCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANPCCharacter::SetRole(const FRole& role)
{
	m_Role = role;
}

void ANPCCharacter::SetInteracting(bool isInteracting)
{
	m_IsInteracting = isInteracting;
}

void ANPCCharacter::SetCurrentBehavior(UTimelineBehaviorSZ* pBeh)
{
	m_pBehavior = pBeh;
}

void ANPCCharacter::SetAction_Implementation(class ASmartZone* pSmartZone, const FString& action)
{
	//Implementation that gets called, if not overriden by Blueprint class
}

void ANPCCharacter::ContinueAnimBlueprint_Implementation()
{
	//Implementation that gets called, if not overriden by Blueprint class
}

const FRole& ANPCCharacter::GetRole()
{
	return m_Role;
}

bool ANPCCharacter::IsInteracting() const
{
	return m_IsInteracting;
}

bool ANPCCharacter::HasBehaviorAnim() const
{
	return m_pBehavior ? m_pBehavior->HasAnim() : false;
}

bool ANPCCharacter::IsBehaviorCompleted() const
{
	return m_IsBehaviorCompleted;
}

void ANPCCharacter::SetBehaviorCompleted(bool isCompleted)
{
	m_IsBehaviorCompleted = isCompleted;
}

