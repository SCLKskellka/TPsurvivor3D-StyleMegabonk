// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataManager.h"
#include "StaticMeshSpawnerSystem.h"
#include "EnemySpawnerComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SURVIVOR3D_API UEnemySpawnerComponent : public UStaticMeshSpawnerSystem
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	UDataManager* DataManager;
	// Sets default values for this component's properties
	UEnemySpawnerComponent();
protected:
	TArray<FEnemyData*> EnemyTypeData;
	// Called when the game starts
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	virtual void MeshSetup() override;
	virtual void SpawnStaticMesh() override;
	virtual void InstancedMeshesMovements(const float DeltaTime) override;
	
	
};
