// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyData.h"
#include "GameFramework/Actor.h"
#include "EnemySpawnerSystem.generated.h"

UCLASS()
class SURVIVOR3D_API AEnemySpawnerSystem : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Enemy")
	float MinOffset;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Enemy")
	float MaxOffset;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Enemy")
	FVector2D RandomSpawnTime;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(RowType="EnemyData"), Category="Enemy")
	FDataTableRowHandle Enemy;
	
	AEnemySpawnerSystem();
	
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Tick(float DeltaSecond) override;

	void SpawnStaticMesh();
	/**
	 * for each enemy
	 * - create enemy static mesh
	 * - set their beginning position
	 * - set their Data
	 */
	void EnemyInitiation();
	/**
	 *	for each enemy
	 *  - movement calculation
	 *  - set new position
	 *  - update data transform
	 */
	void EnemyMovement();
	/**
	 * search the nearest enemy and subtract his hp by damage
	 * @param impactLocation 
	 */
	void TakeDamageBy(FVector3d impactLocation, float damage);
	/**
	 * set the feedback UI of mobs
	 */
protected:
	
	TArray<FEnemyData*> Enemies;

#pragma region component
protected:
	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* InstancedStaticMeshComponent;
	
#pragma endregion
};
