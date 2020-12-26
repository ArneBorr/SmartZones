#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RoleManager.h"
#include "NPCCharacter.generated.h"

UCLASS()
class GW_SMARTZONES_API ANPCCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ANPCCharacter();
	void SetRole(const FRole& role);
	void SetInteracting(bool isInteracting);

	UFUNCTION(BlueprintCallable)
		const FRole& GetRole();
	UFUNCTION(BlueprintCallable)
		bool IsInteracting();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	FRole m_Role;
	bool m_IsInteracting = false;
};
