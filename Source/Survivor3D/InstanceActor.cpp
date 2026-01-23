
#include "InstanceActor.h"

#include "Components/InstancedStaticMeshComponent.h"


AInstanceActor::AInstanceActor()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	
	InstancedStaticMeshComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstancedStaticMesh"));
	SetRootComponent(InstancedStaticMeshComponent);
	InstancedStaticMeshComponent->SetMobility (EComponentMobility::Static);
	EnemyManager = CreateDefaultSubobject<UEnemyManager>(TEXT("EnemyManager"));
}

void AInstanceActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	
	if (InstancedStaticMeshComponent->GetInstanceCount()==0)
	{
		EnemyManager->EnemySpawnInit();
		
		/*TArray<FTransform> Transforms;
		Transforms.Empty(10);
		for (int Index = 0; Index<10; Index++)
		{
			Transforms.Add(FTransform(FVector(100.f * Index,0.f,0.f)));
		}
		InstancedStaticMeshComponent->AddInstances(Transforms, false);*/
	}
}

// Called every frame
void AInstanceActor::Tick(const float DeltaSecond)
{
	Super::Tick(DeltaSecond);
	
	for (int Index = 0; Index < 10; Index++)
	{
		const float Offset = 100.f * sin(2 * PI * 1.f * GetWorld()->GetTimeSeconds());
		
		FTransform OffsetTransform = FTransform(FVector(100.f * Index + Offset,0.f,0.f));
		InstancedStaticMeshComponent->UpdateInstanceTransform(Index, OffsetTransform, false, false, true);
	}
	
	InstancedStaticMeshComponent->MarkRenderStateDirty();
}

