// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableObject.generated.h"


UENUM(BlueprintType)
enum class ERarity : uint8 {
	Common        UMETA(DisplayName = "Common"),
	Rare       UMETA(DisplayName = "Rare"),
	Epic        UMETA(DisplayName = "Epic"),
	Legendary        UMETA(DisplayName = "Legendary"),

};
UENUM(BlueprintType)
enum class EInteractionType : uint8 {
	Weapon        UMETA(DisplayName = "Weapon"),
	Ammo       UMETA(DisplayName = "Ammo"),
	Equipment        UMETA(DisplayName = "Equipment"),
	

};


UCLASS()
class SIMPLEAPOCALYPSE_API AInteractableObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly)
	ERarity Rarity;

	
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* BoxCollider;

public:
	EInteractionType InteractionType;

	bool IsInteractable;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void DissableInteractable();

private:
	void SetHighlightColour();
	void SetHighlight(bool value);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
