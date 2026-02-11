// Fill out your copyright notice in the Description page of Project Settings.

#include "WaveSpawner.h"
#include "EnemyData.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AWaveSpawner::AWaveSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	InstancedStaticMeshComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstancedStaticMeshComponent"));
	InstancedStaticMeshComponent->Mobility = EComponentMobility::Movable;
}

// Called when the game starts or when spawned
void AWaveSpawner::BeginPlay()
{
	Super::BeginPlay();
	Spawn();
	//DataManager = UGameplayStatics::GetGameInstance(GetWorld())->GetSubsystem<UDataManager>();
}

// Called every frame
void AWaveSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	EnemyMovements(DeltaTime);
}

void AWaveSpawner::Spawn()
{
	SetupArrayData();
}

void AWaveSpawner::SetupArrayData()
{
	Enemy.DataTable->GetAllRows("",Enemies);
	SetupEnemiesPosition();
}

void AWaveSpawner::SetupEnemiesPosition()
{
	FVector3d PlayerLocation = UGameplayStatics::GetPlayerPawn(this, 0)->GetActorLocation();
	for (int i = 0; i < Enemies.Max(); i++)
	{
		if(FMath::RandRange(0,1) == 0)
		{
			float xPos = FMath::RandRange( PlayerLocation.X - MinOffset,
				 PlayerLocation.X - MaxOffset );
			float yPos = FMath::RandRange( PlayerLocation.Y - MinOffset,
				 PlayerLocation.Y - MaxOffset );
			FVector3d newLocation =  FVector3d(xPos,yPos, UGameplayStatics::GetPlayerPawn(this, 0)->GetActorLocation().Z);
			Enemies[i]->Position = newLocation;
		}
		else
		{
			float xPos = FMath::RandRange( PlayerLocation.X + MinOffset,
				 PlayerLocation.X + MaxOffset );
			float yPos = FMath::RandRange( PlayerLocation.Y + MinOffset,
				 PlayerLocation.Y + MaxOffset );
			FVector3d newLocation =  FVector3d(xPos,yPos, PlayerLocation.Z);
			Enemies[i]->Position = newLocation;
		}
	}
	
	
	SpawnStaticMeshes();
}

void AWaveSpawner::SpawnStaticMeshes()
{
	if (Enemies.Max() > 0)
	{
		for (int i = 0; i < Enemies.Max(); i++)
		{
			InstancedStaticMeshComponent->SetStaticMesh(Enemies[i]->EnemyMesh);
			InstancedStaticMeshComponent->AddInstance(FTransform(Enemies[i]->Position), false);
		}
	}
}

void AWaveSpawner::EnemyMovements(float DeltaTime)
{
	if(UGameplayStatics::GetPlayerCharacter(GetWorld(),0) && InstancedStaticMeshComponent->GetInstanceCount() > 0)
	{
		FVector3d PlayerLocation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();
	
		for (int32 i = 0; i < InstancedStaticMeshComponent->GetInstanceCount(); i++)
		{
			if (FVector::Dist(Enemies[i]->Position, PlayerLocation) > Enemies[i]->DamageRange)
			{
				FTransform InstanceTransform;
				InstancedStaticMeshComponent->GetInstanceTransform(i, InstanceTransform, true);

				Enemies[i]->Position = InstanceTransform.GetLocation();
				FVector Direction = (PlayerLocation - Enemies[i]->Position).GetSafeNormal();

				Enemies[i]->Position += Direction * Enemies[i]->Speed * DeltaTime;
				InstanceTransform.SetLocation(Enemies[i]->Position);
		
				InstancedStaticMeshComponent->UpdateInstanceTransform(
					i,
					InstanceTransform,
					true,   // world space
					false,  // pas de rendu immédiat
					true    // collision update
				);
			}
		}
		InstancedStaticMeshComponent->MarkRenderStateDirty(); // update rendu une seule fois
	}
}

