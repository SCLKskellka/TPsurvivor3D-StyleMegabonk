#pragma once

#include "CoreMinimal.h"
#include "ProjectileData.generated.h"

USTRUCT()
struct SURVIVOR3D_API FProjectileData : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FVector Position;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Damage;
	
};
