// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataManager.h"
#include "EnemyData.h"
#include "GameFramework/Actor.h"
#include "WaveSpawner.generated.h"

UCLASS()
class SURVIVOR3D_API AWaveSpawner : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(RowType="EnemyData"), Category="Basic Setup")
	FDataTableRowHandle Enemy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Basic Setup")
	float MinOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Basic Setup")
	float MaxOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Basic Setup")
	UInstancedStaticMeshComponent* InstancedStaticMeshComponent;
	
	AWaveSpawner();
protected:
	//UDataManager* DataManager;
	
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void Spawn();
	void SetupArrayData();
	void SetupEnemiesPosition();
	void SpawnStaticMeshes();
	void EnemyMovements(float DeltaTime);
	
private:
	TArray<FEnemyData*> Enemies;
};
