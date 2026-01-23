
#include "EnemyManager.h"

#include "BehaviorTree/BlackboardComponent.h"


UEnemyManager::UEnemyManager()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UEnemyManager::BeginPlay()
{
	Super::BeginPlay();
	
}

void UEnemyManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UEnemyManager::EnemySpawnInit()
{
	AController::GetPawn()->GetActorLocation();
	/*AllEnemyData.Empty(BlackBoardComponent->GetNumKeys());
	BlackBoardComponent->
	for (int i = 0; i < BlackBoardComponent->GetNumKeys(); ++i)
	{
		AllEnemyData[i] = BlackBoardComponent->GetClass()[i];
	}*/
	//Squad->GetKeys().Max();
}

void UEnemyManager::EnemyMovement()
{
	
}

void UEnemyManager::TakeDamage(FVector3d impactLocation, float damage)
{
}

void UEnemyManager::UpdateUI()
{
}

