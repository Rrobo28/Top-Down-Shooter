// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraControllerComponent.h"

UCameraControllerComponent::UCameraControllerComponent()
{

	PrimaryComponentTick.bCanEverTick = true;
	

	

}

void UCameraControllerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCameraControllerComponent::BeginPlay()
{
	Super::BeginPlay();
}
