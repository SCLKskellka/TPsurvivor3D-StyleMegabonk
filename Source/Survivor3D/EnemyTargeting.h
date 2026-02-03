// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyData.h"
#include "Components/ActorComponent.h"
#include "EnemyTargeting.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SURVIVOR3D_API UEnemyTargeting : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(RowType="EnemyData"), Category="EnemyData")
	FDataTableRowHandle EnemyData;
	
	// Sets default values for this component's properties
	UEnemyTargeting();

protected:
	TArray<FEnemyData*> EnemiesData;
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
private:
	FEnemyData* SearchClosestEnemy();
};
