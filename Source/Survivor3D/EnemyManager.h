
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
	UBlackboardData* Squad;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D RandomSpawnTime;
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	void EnemyInit();
	void EnemyMovement();
	void TakeDamage();
	void UpdateUI();
private:
	UPROPERTY(VisibleAnywhere)
	TArray<UBlackboardData*> AllEnemyData;
	
	
};
