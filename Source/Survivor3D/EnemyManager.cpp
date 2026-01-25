
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
	//AController::GetPawn()->GetActorLocation();
	AllEnemyData.Empty(BlackBoardComponent->GetNumKeys());
	for (int i = 0; i < BlackBoardComponent->GetNumKeys(); ++i)
	{
		if(FMath::RandRange(0,1) == 0)/*if behind player*/
		{
			float xPos = FMath::RandRange(AController::GetPawn()->GetActorLocation().X - MinOffset,
				AController::GetPawn()->GetActorLocation().X - MaxOffset );
			float yPos = FMath::RandRange(AController::GetPawn()->GetActorLocation().Y - MinOffset,
				AController::GetPawn()->GetActorLocation().Y - MaxOffset );

			FVector3d newLocation =  FVector3d(xPos,yPos,AController::GetPawn()->GetActorLocation().Z);

			//BlackBoardComponent->SetValue<FVector3d>();
		}
		else
		{
			float xPos = FMath::RandRange(AController::GetPawn()->GetActorLocation().X - MinOffset,
				AController::GetPawn()->GetActorLocation().X + MaxOffset );
			float yPos = FMath::RandRange(AController::GetPawn()->GetActorLocation().Y - MinOffset,
				AController::GetPawn()->GetActorLocation().Y + MaxOffset );
		}
		
	}
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

