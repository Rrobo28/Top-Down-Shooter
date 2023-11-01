// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseComponent.h"

// Sets default values for this component's properties
UBaseComponent::UBaseComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	OwningCharacter = Cast<APlayerCharacter>(GetOwner());
}


// Called when the game starts
void UBaseComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UBaseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

