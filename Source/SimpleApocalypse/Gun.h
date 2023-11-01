// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Bullet.h"
#include "CoreMinimal.h"
#include "Weapon.h"
#include "Gun.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEAPOCALYPSE_API AGun : public AWeapon
{
	GENERATED_BODY()

public:
	AGun();
	
private:
	

	float FireRate;
	float MagSize;
	float ReloadSpeed;

	float Accuracy;
	
public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABullet> Bullet;

	UPROPERTY(EditDefaultsOnly)
	USceneComponent* BulletSpawn;

	UPROPERTY(EditDefaultsOnly)
	float BulletVelocity;

};
