// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetingComponent.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


UTargetingComponent::UTargetingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	//DataManager = UGameplayStatics::GetGameInstance(GetWorld())->GetSubsystem<UDataManager>();
}
void UTargetingComponent::BeginPlay()
{
	Super::BeginPlay();
}
void UTargetingComponent::TickComponent(float DeltaTime, ELevelTick TickType,
										 FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTargetingComponent::RotateToTarget(FVector targetPosition)
{
	FVector direction = (targetPosition - GetOwner()->GetActorLocation()).GetSafeNormal();
	FRotator rot = UKismetMathLibrary::MakeRotFromXZ(direction, FVector::UpVector);
	TargetingPivot->SetWorldRotation(rot,false,nullptr,static_cast<ETeleportType>(true));
}

