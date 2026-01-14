// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Weapon.generated.h"

UENUM(BlueprintType)
enum class EGrowingStats : uint8
{
	Damage UMETA(DisplayName="Damage", ToolTip="Increase weapon's damage (value)"),
	AttackFrequency UMETA(DisplayName="AttackFrequency", ToolTip="Increase weapon's attack frequency (%)"),
	CritDamage UMETA(DisplayName="CritDamage", ToolTip="Increase weapon's critical damage (%)"),
	ProjectileSize UMETA(DisplayName="ProjectileSize", ToolTip="Increase projectile's size (%)"),
	ProjectileCount UMETA(DisplayName="ProjectileCount", ToolTip="Increase number of projectile (value)")
};

UCLASS()
class SURVIVOR3D_API AWeapon : public AItem
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeapon();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	int Level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	int Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	float AttackFrequency;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	float CritDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	float ProjectileSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	float ProjectileCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	TMap<EGrowingStats, float> GrowingStats;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
