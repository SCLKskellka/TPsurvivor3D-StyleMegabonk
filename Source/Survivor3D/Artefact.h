// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Artefact.generated.h"

UENUM(BlueprintType)
enum class EStats : uint8
{
	NewStat UMETA(Hidden),
	Life UMETA(DisplayName="Life", ToolTip="Increase the max life of the character (value)"),
	LifeRegeneration UMETA(DisplayName="LifeRegeneration", ToolTip="Increase the life regeneration of the character (value)"),
	Shield UMETA(DisplayName="Shield", ToolTip="Increase the max shield of the character (value)"),
	Armor UMETA(DisplayName="Armor", ToolTip="Reduce damage get by the character (%)"),
	Dodge UMETA(DisplayName="Dodge", ToolTip="Increase the capability of the character to dodge damage(%)"),
	LifeSteal UMETA(DisplayName="LifeSteal", ToolTip="Increase the capability of the character to heal by a percentage of his damage (%)"),
	Horn UMETA(DisplayName="Horn", ToolTip="Increase the damage return to an ennemy when character take damage by (value)"),
	
	DamageMultiplication UMETA(DisplayName="Damage", ToolTip="Increase the damage of the character (*)"),
	CriticalChance UMETA(DisplayName="CriticalChance", ToolTip="Add chance to make a critical hit (%)"),
	CriticalDamageMultiplication UMETA(DisplayName="CriticalDamage", ToolTip="Increase critical damage (*)"),
	ProjectileQuantity UMETA(DisplayName="ProjectileQuantity"),
	ProjectileBounce UMETA(DisplayName="ProjectileBounce"),
	AttackSpeed UMETA(DisplayName="AttackSpeed"),
	EliteDamageMultiplication UMETA(DisplayName="EliteDamage"),
	DurationMultiplication UMETA(DisplayName="Duration"),
	SizeMultiplication UMETA(DisplayName="Size"),
	ProjectileSpeedMultiplication UMETA(DisplayName="ProjectileSpeed"),

	ChanceMultiplication UMETA(DisplayName="Chance"),
	JumpQuantity UMETA(DisplayName="JumpQuantity"),
	JumpHeight UMETA(DisplayName="JumpHeight"),
	HarvestRange UMETA(DisplayName="HarvestRange"),	
	XPMultiplication UMETA(DisplayName="XP"),
	GoldMultiplication UMETA(DisplayName="Gold"),
	DropQualityMultiplication UMETA(DisplayName="DropQuality"),
	PowerUpQuantityMultiplication UMETA(DisplayName="PowerUpQuantity")
	
};

UCLASS()
class SURVIVOR3D_API AArtefact : public AItem
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AArtefact();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Property")
	int Stack = 1;
	/**
	 * Stats
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	TMap<EStats, float> Stats;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

