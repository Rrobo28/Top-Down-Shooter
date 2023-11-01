// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "PlayerMovementComponent.h"
#include "Gun.h"
#include "PlayerInventoryComponent.h"
#include "CoreMinimal.h"
#include "BaseComponent.h"
#include "PlayerShootingComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SIMPLEAPOCALYPSE_API UPlayerShootingComponent : public UBaseComponent
{
	GENERATED_BODY()


public:
	UPlayerShootingComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:
	virtual void SetupPlayerInputComponent();

	void ShootPressed();
	void ShootReleased();

	void SpawnBullet();
private:
	UPlayerInventoryComponent* Inventory;
	UPlayerMovementComponent* Movement;
	bool IsShooting = false;
	bool ShootHeld= false;
	AGun* Gun;
	
};
