#pragma once

#include "CoreMinimal.h"
#include "EnemyData.generated.h"

USTRUCT(BlueprintType)
struct SURVIVOR3D_API FEnemyData: public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Name;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FVector Position;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Damage;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Speed;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMesh* EnemyMesh;
};
