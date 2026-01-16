
#include "EnemyManager.h"


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

void UEnemyManager::EnemyInit()
{
	//AllEnemyData.Empty(Squad->GetKeys().Max());
	//Squad->Get
	/*for (int i = 0; i < Squad->GetKeys().Max(); ++i)
	{
		AllEnemyData[i] = Squad->GetClass()[i];
	}*/
	//Squad->GetKeys().Max();
}

void UEnemyManager::EnemyMovement()
{
	
}

void UEnemyManager::TakeDamage()
{
}

void UEnemyManager::UpdateUI()
{
}

