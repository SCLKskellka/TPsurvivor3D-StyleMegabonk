// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AProjectileBase.h"
#include "Projectile.h"
#include "Components/ActorComponent.h"
#include "ProjectileShooterComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SURVIVOR3D_API UProjectileShooterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UProjectileShooterComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AProjectileBase> Projectile = AProjectileBase::StaticClass();

	UPROPERTY(EditAnywhere)
	int ShotPower;
	UPROPERTY(EditAnywhere)
	FVector targetLocation;
	UPROPERTY(EditAnywhere)
	FTransform ProjectileSpawnOffset;
	
	UPROPERTY()
	int projectileDamage;
	FTimerHandle TimerHandle;

	UFUNCTION(BlueprintCallable)
	void ShootAtLocation() const;


};
