// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "PlayerCharacter.generated.h"


UCLASS()
class SIMPLEAPOCALYPSE_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()


public: 
	APlayerCharacter();
	UCameraComponent* GetCamera();
	USpringArmComponent* GetSpringArm();
private:

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;
};
