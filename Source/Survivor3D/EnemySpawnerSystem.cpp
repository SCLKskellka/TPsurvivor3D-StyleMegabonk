
#include "EnemySpawnerSystem.h"

#include "EnemyData.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"


AEnemySpawnerSystem::AEnemySpawnerSystem()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	
	InstancedStaticMeshComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstancedStaticMesh"));
	SetRootComponent(InstancedStaticMeshComponent);
	InstancedStaticMeshComponent->SetMobility (EComponentMobility::Static);
}

void AEnemySpawnerSystem::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
}

void AEnemySpawnerSystem::BeginPlay()
{
	Super::BeginPlay();
	EnemySetup();
}

// Called every frame
void AEnemySpawnerSystem::Tick(const float DeltaSecond)
{
	Super::Tick(DeltaSecond);
	EnemiesMovements(DeltaSecond);
}

void AEnemySpawnerSystem::SpawnStaticMesh()
{
	TArray<FTransform> Transforms;
	for (int i = 0; i < Enemies.Num(); i++)
	{
		if (Enemies[i]->EnemyMesh != nullptr)
		{
			InstancedStaticMeshComponent->SetStaticMesh(Enemies[i]->EnemyMesh);
			InstancedStaticMeshComponent->AddInstance(FTransform(Enemies[i]->Position), false);
		}
	}
}

void AEnemySpawnerSystem::EnemySetup()
{
	if (!Enemy.IsNull())
	{
		Enemy.DataTable->GetAllRows("",Enemies);
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
		SpawnStaticMesh();
	}
}

void AEnemySpawnerSystem::EnemiesMovements(const float DeltaSecond)
{
	if(UGameplayStatics::GetPlayerCharacter(GetWorld(),0))
	{
		FVector3d PlayerLocation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();
	
		for (int32 i = 0; i < InstancedStaticMeshComponent->GetInstanceCount(); i++)
		{
			FTransform InstanceTransform;
			InstancedStaticMeshComponent->GetInstanceTransform(i, InstanceTransform, true);

			Enemies[i]->Position = InstanceTransform.GetLocation();
			FVector Direction = (PlayerLocation - Enemies[i]->Position).GetSafeNormal();

			Enemies[i]->Position += Direction * Enemies[i]->Speed * DeltaSecond;
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


