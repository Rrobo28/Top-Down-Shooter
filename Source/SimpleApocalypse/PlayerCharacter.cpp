// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

APlayerCharacter::APlayerCharacter()
{
	Tags.Add(TEXT("Player"));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));

	//Attach Camera and Spring Arm to Root Component
	SpringArm->SetupAttachment(RootComponent);
	Camera->SetupAttachment(SpringArm);
}







UCameraComponent* APlayerCharacter::GetCamera()
{
	return Camera;
}

USpringArmComponent* APlayerCharacter::GetSpringArm()
{
	return SpringArm;
}
