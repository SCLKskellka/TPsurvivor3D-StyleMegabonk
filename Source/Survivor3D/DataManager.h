// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyData.h"
#include "GameFramework/Actor.h"
#include "DataManager.generated.h"

UCLASS()
class SURVIVOR3D_API ADataManager : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(RowType="EnemyData"), Category="Enemy")
	FDataTableRowHandle Bestiary;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(RowType="EnemyData"), Category="Enemy")
	FDataTableRowHandle EnemyDataList;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(RowType="PlayerData"), Category="Player")
	FDataTableRowHandle PlayerData;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(RowType="ProjectileData"), Category="Player")
	FDataTableRowHandle ProjectileDataList;
	
	// Sets default values for this actor's properties
	ADataManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
