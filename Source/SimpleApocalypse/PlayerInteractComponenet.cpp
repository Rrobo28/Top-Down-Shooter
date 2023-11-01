// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInteractComponenet.h"

UPlayerInteractComponenet::UPlayerInteractComponenet()
{
	
	if (!OwningCharacter) return;
	OwningCharacter->GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &UPlayerInteractComponenet::OnOverlapBegin);
	OwningCharacter->GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &UPlayerInteractComponenet::OnEndOverlap);
}

void UPlayerInteractComponenet::BeginPlay()
{
	if (!OwningCharacter) return;
	ObjectsInRange.Empty();

	AnimationComponent = OwningCharacter->GetComponentByClass<UPlayerAnimationComponent>();
	Inventory = OwningCharacter->GetComponentByClass<UPlayerInventoryComponent>();

	SetupPlayerInputComponent();
}

void UPlayerInteractComponenet::SetupPlayerInputComponent()
{
	OwningCharacter->InputComponent->BindAction("Interact", EInputEvent::IE_Pressed, this, &UPlayerInteractComponenet::Interact);
}

void UPlayerInteractComponenet::Interact()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello"));
	if (ObjectsInRange.Num() > 0)
	{
		AInteractableObject* obj = ObjectsInRange[0];

		obj->DissableInteractable();

		if (obj->InteractionType == EInteractionType::Weapon)
		{
			PickUp(Cast<AWeapon>(obj));
		}
		
		ObjectsInRange.RemoveAt(0);
	}
}

void UPlayerInteractComponenet::PickUp(AWeapon* Weapon)
{
	AttachToHand(Weapon);

	Inventory->Weapons.Add(Weapon);
	Inventory->CurrentWeapon = Weapon;
	UE_LOG(LogTemp, Warning, TEXT("PickUP"));
	AnimationComponent->UpdateWeaponAnimations();

}

void UPlayerInteractComponenet::AttachToHand(AWeapon* Weapon)
{
	if (Weapon->WeaponType == EWeaponType::Primary) 
	{
		Weapon->AttachToComponent(OwningCharacter->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, "Primary Weapon Socket");
		
		
	}
	else if (Weapon->WeaponType == EWeaponType::Secondary)
	{
		Weapon->AttachToComponent(OwningCharacter->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, "Secondary Weapon Socket");
	

	}
	
	Weapon->SetActorRelativeLocation(FVector(0, 0, 0));
	Weapon->SetActorRelativeRotation(FRotator(0, 0, 0));
}

void UPlayerInteractComponenet::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Interactable"))
	{
		ObjectsInRange.Add( Cast<AInteractableObject>(OtherActor));
	}

}

void UPlayerInteractComponenet::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	if (OtherActor->ActorHasTag("Interactable"))
	{
		ObjectsInRange.Remove(Cast<AInteractableObject>(OtherActor));
	}
}
