// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyData.h"
//#include "FPlayerData.h"
#include "ProjectileData.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DataManager.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVOR3D_API UDataManager : public UEngineSubsystem 
{
	GENERATED_BODY()
	
public:
	TArray<FEnemyData*> LivingEnemiesData;
	//TArray<FPlayerData*> PlayerData;
	TArray<FProjectileData*> ProjectileDataList;
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION()
	int GetLivingEnemiesDataSize() const {return LivingEnemiesData.Max();}
	UFUNCTION()
	void CheckDamage();
};
