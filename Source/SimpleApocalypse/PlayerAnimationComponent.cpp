// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnimationComponent.h"

UPlayerAnimationComponent::UPlayerAnimationComponent()
{
	if (!OwningCharacter) return;
	Inventory = OwningCharacter->GetComponentByClass<UPlayerInventoryComponent>();
}



void UPlayerAnimationComponent::UpdateWeaponAnimations()
{
	UE_LOG(LogTemp, Warning, TEXT("Update"));
	if (Inventory->CurrentWeapon->WeaponType == EWeaponType::Primary) 
	{
		ActiveIdleSequence = PrimaryIdleSequence;
		ActiveWalkingBlend = PrimaryWalkingBlend;
	}
	if (Inventory->CurrentWeapon->WeaponType == EWeaponType::Secondary)
	{
		ActiveIdleSequence = SecondaryIdleSequence;
		ActiveWalkingBlend = SecondaryWalkingBlend;
	}
}

void UPlayerAnimationComponent::BeginPlay()
{
	Super::BeginPlay();
	
	ActiveIdleSequence = UnarmedIdleSequence;
	ActiveWalkingBlend = UnarmedWalkingBlend;
}
