// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyData.h"
#include "Components/ActorComponent.h"
#include "PlayerShootingSystem.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SURVIVOR3D_API UPlayerShootingSystem : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(RowType="EnemyData"), Category="EnemyData")
	FDataTableRowHandle EnemyData;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(RowType="ProjectileData"), Category="Player")
	FDataTableRowHandle ProjectileData;
	// Sets default values for this component's properties
	UPlayerShootingSystem();

protected:
	TArray<FEnemyData*> EnemiesData;
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	FEnemyData SearchClosestEnemy();
	
	UFUNCTION(BlueprintCallable)
	void Shoot(FVector TargetPosition);
	
	
};
