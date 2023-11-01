// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MyPlayerState.h"
#include "CoreMinimal.h"

#include "BaseComponent.h"
#include "PlayerMovementComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SIMPLEAPOCALYPSE_API UPlayerMovementComponent : public UBaseComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPlayerMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void SetupPlayerInputComponent();

private:
	void MoveHorizontal(float value);

	void MoveVertical(float value);

	void StartSlide();
	void StopSlide();

	void LookAtMouse();
private:

	UPROPERTY(EditDefaultsOnly)
	float WalkSpeed;

	UPROPERTY(EditDefaultsOnly)
	float SlideSpeed;

	

	UMyPlayerState* PlayerState;

	float MoveX;
	float MoveY;
public:
	UPROPERTY(BlueprintReadOnly)
	FVector MoveDirection;
	UPROPERTY(BlueprintReadOnly)
	FRotator LookRotation;

	UPROPERTY(BlueprintReadOnly)
	FVector MouseToWorldPosition;

	UPROPERTY(BlueprintReadOnly)
	FVector MouseNormal;
};

