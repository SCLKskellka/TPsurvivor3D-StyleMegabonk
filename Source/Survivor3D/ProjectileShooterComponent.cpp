// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileShooterComponent.h"
#include "AProjectileBase.h"
#include "DataManager.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values for this component's properties
UProjectileShooterComponent::UProjectileShooterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	ShotPower = 100;
}


// Called when the game starts
void UProjectileShooterComponent::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UProjectileShooterComponent::ShootAtLocation,3,true);
}

// Called every frame
void UProjectileShooterComponent::TickComponent(float DeltaTime, ELevelTick TickType,
												 FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UProjectileShooterComponent::ShootAtLocation() const
{
	if (IsValid(Projectile))
	{
		FVector direction = (targetLocation - GetOwner()->GetActorLocation()).GetSafeNormal();
		UWorld* World = GetOwner()->GetWorld();
		if (IsValid(World))
		{
			FTransform SpawnTransform = GetOwner()->GetActorTransform();
			AProjectileBase* SpawnedProjectile = World->SpawnActor<AProjectileBase>(Projectile, SpawnTransform);
			SpawnedProjectile->MovementComponent->AddForce(direction*ShotPower*1000);
		}
	}
}


