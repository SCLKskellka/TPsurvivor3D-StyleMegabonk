// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerShootingSystem.h"

#include "EnemyData.h"
#include "Projectile.h"
#include "Chaos/Deformable/ChaosDeformableSolverProxy.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Internal/Kismet/BlueprintTypeConversions.h"


// Sets default values for this component's properties
UPlayerShootingSystem::UPlayerShootingSystem()
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
void UPlayerShootingSystem::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlayerShootingSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FEnemyData UPlayerShootingSystem::SearchClosestEnemy()
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
	return *ClosestEnemy;
}

void UPlayerShootingSystem::Shoot(FVector TargetPosition)
{
	FVector3d PlayerLocation = UGameplayStatics::GetPlayerPawn(this, 0)->GetActorLocation();
	FVector3d ProjectileOffset = (PlayerLocation - TargetPosition).GetSafeNormal()*1.5;
	
	GetWorld()->SpawnActor<AProjectile>();
}

