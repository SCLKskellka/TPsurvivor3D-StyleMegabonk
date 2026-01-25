
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BlackboardData.h"
#include "Components/ActorComponent.h"
#include "EnemyManager.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SURVIVOR3D_API UEnemyManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UEnemyManager();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBlackboardComponent* BlackBoardComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MinOffset;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxOffset;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D RandomSpawnTime;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AInstanceActor * EnemySpawners;
protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	/**
	 * for each enemy
	 * - create enemy static mesh
	 * - set their beginning position
	 * - set their Data
	 */
	void EnemySpawnInit();
	/**
	 *	for each enemy
	 *  - movement calculation
	 *  - set new position
	 *  - update data transform
	 */
	void EnemyMovement();
	/**
	 * search the nearest enemy and subtract his hp by damage
	 * @param impactLocation 
	 */
	void TakeDamage(FVector3d impactLocation, float damage);
	/**
	 * set the feedback UI of mobs
	 */
	void UpdateUI();
private:
	UPROPERTY(VisibleAnywhere)
	TArray<UBlackboardData*> AllEnemyData;
	
	
};
