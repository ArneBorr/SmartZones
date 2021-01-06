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

	UFUNCTION(BlueprintNativeEvent)
		void SetAction(class ASmartZone* pSmartZone, const FString& action);

	UFUNCTION(BlueprintCallable)
		const FRole& GetRole();
	UFUNCTION(BlueprintCallable)
		bool IsInteracting();
	
	bool IsBehaviorCompleted() const;
	void SetBehaviorCompleted(bool isCompleted);

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	FRole m_Role;
	bool m_IsInteracting = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		bool m_IsBehaviorCompleted = false;
};