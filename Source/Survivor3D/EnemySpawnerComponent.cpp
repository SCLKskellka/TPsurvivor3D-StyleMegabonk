// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawnerComponent.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"


// Sets default values for this component's properties
UEnemySpawnerComponent::UEnemySpawnerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}
void UEnemySpawnerComponent::BeginPlay()
{
	Super::BeginPlay();
	DataManager = GEngine->GetEngineSubsystem<UDataManager>();
	MeshSetup();
}
void UEnemySpawnerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	InstancedMeshesMovements(DeltaTime);
}

void UEnemySpawnerComponent::MeshSetup()
{
	Super::MeshSetup();
	if (!DataManager)DataManager = GEngine->GetEngineSubsystem<UDataManager>();
	if (!MeshData.IsNull())
	{
		FVector3d PlayerLocation = UGameplayStatics::GetPlayerPawn(this, 0)->GetActorLocation();
		MeshData.DataTable->GetAllRows("",EnemyTypeData);
		float QttToSpawn =  FMath::RandRange(RandomSpawnQttRange.X, RandomSpawnQttRange.Y);
		for (int i = 0; i < QttToSpawn; i++)
		{
			Enemies.Add(const_cast<TArray<FEnemyData*>::ElementType>(EnemyTypeData[FMath::RandRange(0, EnemyTypeData.Max() - 1)]));
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
		SpawnStaticMesh();
	}
}
void UEnemySpawnerComponent::SpawnStaticMesh()
{
	Super::SpawnStaticMesh();
	if (!DataManager)DataManager = GEngine->GetEngineSubsystem<UDataManager>();
	TArray<FTransform> Transforms;
	if (Enemies.Max() > 0)
	{
		for (FEnemyData* EnemyData : Enemies)
		{
			InstancedStaticMeshComponent->SetStaticMesh(EnemyData->EnemyMesh);
			InstancedStaticMeshComponent->AddInstance(FTransform(EnemyData->Position), false);
		}
		/*for (int i = 0; i < Enemies.Max(); ++i)
		{
			InstancedStaticMeshComponent->SetStaticMesh(Enemies[i]->EnemyMesh);
			InstancedStaticMeshComponent->AddInstance(FTransform(Enemies[i]->Position), false);
		}*/
	}
}

void UEnemySpawnerComponent::InstancedMeshesMovements(float DeltaTime)
{
	Super::InstancedMeshesMovements(DeltaTime);
	if(UGameplayStatics::GetPlayerCharacter(GetWorld(),0))
	{
		FVector3d PlayerLocation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();
	
		for (int32 i = 0; i < InstancedStaticMeshComponent->GetInstanceCount()-1; i++)
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
		InstancedStaticMeshComponent->MarkRenderStateDirty(); // update rendu une seule fois
	}
}


