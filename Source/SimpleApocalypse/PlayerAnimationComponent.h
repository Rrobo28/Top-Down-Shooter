// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Weapon.h"

#include "PlayerInventoryComponent.h"
#include "CoreMinimal.h"
#include "BaseComponent.h"
#include "PlayerAnimationComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SIMPLEAPOCALYPSE_API UPlayerAnimationComponent : public UBaseComponent
{
	GENERATED_BODY()

public:
	UPlayerAnimationComponent();


private: 

	UPlayerInventoryComponent* Inventory;

	UPROPERTY(EditDefaultsOnly)
	UAnimSequence* UnarmedIdleSequence;

	UPROPERTY(EditDefaultsOnly)
	UAnimSequence* PrimaryIdleSequence;

	UPROPERTY(EditDefaultsOnly)
	UAnimSequence* SecondaryIdleSequence;

	UPROPERTY(EditDefaultsOnly)
	UBlendSpace* UnarmedWalkingBlend;

	UPROPERTY(EditDefaultsOnly)
	UBlendSpace* PrimaryWalkingBlend;

	UPROPERTY(EditDefaultsOnly)
	UBlendSpace* SecondaryWalkingBlend;

public:
	void UpdateWeaponAnimations();
private:
	virtual void BeginPlay() override;
public:
	UPROPERTY(BlueprintReadWrite)
	UBlendSpace* ActiveWalkingBlend;
	UPROPERTY(BlueprintReadWrite)
	UAnimSequence* ActiveIdleSequence;
};
