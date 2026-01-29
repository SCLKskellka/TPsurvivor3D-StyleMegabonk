
#include "EnemySpawnerSystem.h"

#include "EnemyData.h"
#include "Components/InstancedStaticMeshComponent.h"
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
	if (UGameplayStatics::GetPlayerPawn(this, 0) != nullptr) EnemyInitiation();
}

// Called every frame
void AEnemySpawnerSystem::Tick(const float DeltaSecond)
{
	Super::Tick(DeltaSecond);
	if (UGameplayStatics::GetPlayerPawn(this, 0) != nullptr && 
		InstancedStaticMeshComponent->GetInstanceCount() ==0)
	{
		EnemyInitiation();
	}
}

void AEnemySpawnerSystem::SpawnStaticMesh()
{
	TArray<FTransform> Transforms;
	for (int i = 0; i < Enemies.Num(); i++)
	{
		if (Enemies[i]->EnemyMesh == nullptr)
		{
			InstancedStaticMeshComponent->SetStaticMesh(Enemies[i]->EnemyMesh);
			InstancedStaticMeshComponent->AddInstance(FTransform(FVector(Enemies[i]->Position)), false);
		}
	}
}

void AEnemySpawnerSystem::EnemyInitiation()
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
				float xPos = FMath::RandRange( PlayerLocation.X - MinOffset,
					 PlayerLocation.X + MaxOffset );
				float yPos = FMath::RandRange( PlayerLocation.Y - MinOffset,
					 PlayerLocation.Y + MaxOffset );
				FVector3d newLocation =  FVector3d(xPos,yPos, PlayerLocation.Z);
				Enemies[i]->Position = newLocation;
			}
		
		}
		SpawnStaticMesh();
	}
}

void AEnemySpawnerSystem::EnemyMovement()
{
	printf("move");
}

void AEnemySpawnerSystem::TakeDamageBy(FVector3d impactLocation, float damage)
{
	printf("hurt");
}

