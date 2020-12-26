
#include "NPCCharacter.h"

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

const FRole& ANPCCharacter::GetRole()
{
	return m_Role;
}

bool ANPCCharacter::IsInteracting()
{
	return m_IsInteracting;
}

