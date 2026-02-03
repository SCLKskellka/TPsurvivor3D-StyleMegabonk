// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyTargeting.h"

#include "EnemyData.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Internal/Kismet/BlueprintTypeConversions.h"


// Sets default values for this component's properties
UEnemyTargeting::UEnemyTargeting()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	if (!EnemyData.IsNull())
	{
		EnemyData.DataTable->GetAllRows("",EnemiesData);
	}
}


// Called when the game starts
void UEnemyTargeting::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEnemyTargeting::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FEnemyData* UEnemyTargeting::SearchClosestEnemy()
{
	FEnemyData* ClosestEnemy = EnemiesData[0];
	FVector3d PlayerLocation = UGameplayStatics::GetPlayerPawn(this, 0)->GetActorLocation();
	for (int i = 0; i < EnemiesData.Max(); ++i)
	{
		if (UKismetMathLibrary::Vector_Distance(PlayerLocation, ClosestEnemy->Position) >
			UKismetMathLibrary::Vector_Distance(PlayerLocation, EnemiesData[i]->Position))
		{
			ClosestEnemy = EnemiesData[i];
		}
	}
	return ClosestEnemy;
}

