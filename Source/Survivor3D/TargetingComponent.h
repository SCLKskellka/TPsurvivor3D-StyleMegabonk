// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataManager.h"
#include "Components/ActorComponent.h"
#include "TargetingComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SURVIVOR3D_API UTargetingComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UTargetingComponent();
protected:
	virtual void BeginPlay() override;
public:

	//TObjectPtr<UDataManager> DataManager;
	UPROPERTY(EditAnywhere)
	USceneComponent* TargetingPivot;
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
	void RotateToTarget(FVector targetPosition);
};
