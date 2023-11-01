// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableObject.h"

// Sets default values
AInteractableObject::AInteractableObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetupAttachment(Mesh);
	Rarity = ERarity::Common;

	Mesh->bRenderCustomDepth = false;

	Tags.Add(TEXT("Interactable"));

	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AInteractableObject::OnOverlapBegin);

	BoxCollider->OnComponentEndOverlap.AddDynamic(this, &AInteractableObject::OnEndOverlap);

	IsInteractable = true;
}

// Called when the game starts or when spawned
void AInteractableObject::BeginPlay()
{
	Super::BeginPlay();
	
	SetHighlightColour();

	
}

// Called every frame
void AInteractableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractableObject::SetHighlight(bool value)
{
	if (value)
	{
		Mesh->SetRenderCustomDepth(true);
	}
	else
	{
		Mesh->SetRenderCustomDepth(false);
	}
}

void AInteractableObject::DissableInteractable()
{
	

	IsInteractable = false;

	SetHighlight(false);
	
	BoxCollider->SetActive(false);

}

void AInteractableObject::SetHighlightColour()
{
	Mesh->CustomDepthStencilValue = (uint32)Rarity;
}

void AInteractableObject::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor->ActorHasTag("Player") && IsInteractable)
	{
		SetHighlight(true);
	}
}

void AInteractableObject::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->ActorHasTag("Player") && IsInteractable)
	{
		SetHighlight(false);
	}
}

