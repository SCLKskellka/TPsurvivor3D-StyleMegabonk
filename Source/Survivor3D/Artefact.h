// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Artefact.generated.h"

UCLASS()
class SURVIVOR3D_API AArtefact : public AItem
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AArtefact();
	UPROPERTY(BlueprintReadOnly, Category="Property")
	int Stack = 1;
	/**
	 * Stats
	 */
	int Life;
	int LifeRegeneration;
	int Shield;
	float Armor;
	float Dodge;
	float OverHeal;
	float LifeSteal;
	int Horn;
	
	float DamageMultiplication;
	float CriticalChance;
	float CriticalDamageMultiplication;
	int ProjectileQuantity;
	int ProjectileBounce;
	float AttackSpeed;
	float EliteDamageMultiplication;
	float DurationMultiplication;
	float SizeMultiplication;
	float ProjectileSpeedMultiplication;

	float ChanceMultiplication;
	int JumpQuantity;
	int JumpHeight;
	int HarvestRange;
	float XPMultiplication;
	float GoldMultiplication;
	float DropQualityMultiplication;
	float PowerUpQuantityMultiplication;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
