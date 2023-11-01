// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Weapon.h"
#include "CoreMinimal.h"
#include "BaseComponent.h"
#include "PlayerInventoryComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SIMPLEAPOCALYPSE_API UPlayerInventoryComponent : public UBaseComponent
{
	GENERATED_BODY()

public:

	TArray<AWeapon*> Weapons;

	AWeapon* CurrentWeapon;
	
};
