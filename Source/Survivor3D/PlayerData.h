#pragma once

#include "CoreMinimal.h"
#include "PlayerData.generated.h"

USTRUCT()
struct SURVIVOR3D_API FPlayerData : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MaxHealth;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Health;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Range;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Damage;
};
