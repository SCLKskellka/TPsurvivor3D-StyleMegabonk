// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Weapon.generated.h"

UCLASS()
class SURVIVOR3D_API AWeapon : public AItem
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeapon();
	UPROPERTY(BlueprintReadWrite, Category="Stats")
	int Damage;
	UPROPERTY(BlueprintReadWrite, Category="Stats")
	float AttackFrequency;
	UPROPERTY(BlueprintReadWrite, Category="Stats")
	float CritDamage;
	UPROPERTY(BlueprintReadWrite, Category="Stats")
	int Level;
	UPROPERTY(BlueprintReadWrite, Category="Stats")
	int LevelGrowth;
	UPROPERTY(BlueprintReadWrite, Category="Stats")
	float ProjectileSize;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
