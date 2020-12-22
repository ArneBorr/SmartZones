
#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RoleManager.generated.h"

USTRUCT(BlueprintType)
struct FRole
{
	GENERATED_BODY()
public:
	FRole() {};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Name = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int CardinalityMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int CardinalityMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int CurrentNrOfNPCsWithThisRole = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CanJoinDynamically = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ShouldBeSendAwayAtEnd = false;
};

UCLASS()
class GW_SMARTZONES_API URoleManager : public UObject
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable)
		void AddRole(const FRole& role);

private:

	TArray<FRole> m_Roles;
};


