
#include "StaticMeshSpawnerSystem.h"

#include "EnemyData.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"


UStaticMeshSpawnerSystem::UStaticMeshSpawnerSystem()
{
	PrimaryComponentTick.bCanEverTick = true;
	
	InstancedStaticMeshComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstancedStaticMesh"));
	InstancedStaticMeshComponent->SetMobility (EComponentMobility::Static);
}

void UStaticMeshSpawnerSystem::BeginPlay()
{
	Super::BeginPlay();
	MeshSetup();
}

void UStaticMeshSpawnerSystem::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	InstancedMeshesMovements(DeltaTime);
}

void UStaticMeshSpawnerSystem::InstancedMeshesMovements(float DeltaTime)
{
}

void UStaticMeshSpawnerSystem::MeshSetup()
{
}

void UStaticMeshSpawnerSystem::SpawnStaticMesh()
{
}






