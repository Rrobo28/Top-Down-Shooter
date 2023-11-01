// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "PlayerAnimationComponent.h"

#include "Components/CapsuleComponent.h"
#include "PlayerInventoryComponent.h"
#include"Weapon.h"
#include "InteractableObject.h"
#include "CoreMinimal.h"
#include "BaseComponent.h"
#include "PlayerInteractComponenet.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SIMPLEAPOCALYPSE_API UPlayerInteractComponenet : public UBaseComponent
{
	GENERATED_BODY()

public:
	UPlayerInteractComponenet();
private:
	
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent();
	void Interact();

	void PickUp(AWeapon* Weapon);

	void AttachToHand(AWeapon* Weapon);
	void AddToInventory(AWeapon* Weapon);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	UPlayerAnimationComponent* AnimationComponent;

	UPlayerInventoryComponent* Inventory;

public:
	TArray<AInteractableObject*> ObjectsInRange;
	
};
