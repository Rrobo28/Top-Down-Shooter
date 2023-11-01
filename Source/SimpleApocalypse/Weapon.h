// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableObject.h"
#include "Weapon.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EWeaponType : uint8 {
    Melee        UMETA(DisplayName = "Melee"),
    Primary        UMETA(DisplayName = "Primary"),
    Secondary       UMETA(DisplayName = "Secondary"),

};

UCLASS()
class SIMPLEAPOCALYPSE_API AWeapon : public AInteractableObject
{
	GENERATED_BODY()
	
public:
	AWeapon();

protected:
	float Damage;

public:
	UPROPERTY(EditDefaultsOnly)
	EWeaponType WeaponType;
};
