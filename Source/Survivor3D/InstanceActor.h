// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyManager.h"
#include "GameFramework/Actor.h"
#include "InstanceActor.generated.h"

UCLASS()
class SURVIVOR3D_API AInstanceActor : public AActor
{
	GENERATED_BODY()

public:
	AInstanceActor();
	
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Tick(float DeltaSecond) override;

protected:

#pragma region component
protected:
	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* InstancedStaticMeshComponent;
	
	UPROPERTY(VisibleAnywhere)
	UEnemyManager* EnemyManager;
#pragma endregion
};
