// Fill out your copyright notice in the Description page of Project Settings.


#include "DataManager.h"

UDataManager::UDataManager()
{
}

void UDataManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UDataManager::Deinitialize()
{
	Super::Deinitialize();
}

void UDataManager::UpdateEnemies(TArray<FEnemyData*> WaveData)
{
	for (int i = 0; i < WaveData.Max(); ++i)
	{
		Enemies[i] = *WaveData[i];
	}
}
