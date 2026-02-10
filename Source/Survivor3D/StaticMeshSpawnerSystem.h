// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyData.h"
#include "GameFramework/Actor.h"
#include "StaticMeshSpawnerSystem.generated.h"

UCLASS()
class SURVIVOR3D_API UStaticMeshSpawnerSystem : public UActorComponent
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Statistique")
	float MinOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Statistique")
	float MaxOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Statistique")
	FVector2D RandomSpawnTimeRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Statistique")
	FVector2D RandomSpawnQttRange;
	/**
	 * Data table where each type of object we want to instance are grouped
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	FDataTableRowHandle MeshData;
	
	UStaticMeshSpawnerSystem();
	
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
	virtual void MeshSetup();
	virtual void SpawnStaticMesh();
	virtual void InstancedMeshesMovements(float DeltaTime);

#pragma region component
	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* InstancedStaticMeshComponent;
#pragma endregion
};
