// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMovementComponent.h"
#include "DrawDebugHelpers.h"
// Fill out your copyright notice in the Description page of Project Settings.
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "PlayerMovementComponent.h"

// Sets default values for this component's properties
UPlayerMovementComponent::UPlayerMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	
	MoveX = 0;
	MoveY = 0;
}


// Called when the game starts
void UPlayerMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	PlayerState = OwningCharacter->GetComponentByClass<UMyPlayerState>();

	SetupPlayerInputComponent();

	

}


// Called every frame
void UPlayerMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	LookAtMouse();
}

void UPlayerMovementComponent::SetupPlayerInputComponent()
{
	OwningCharacter->InputComponent->BindAxis("Horizontal", this, &UPlayerMovementComponent::MoveHorizontal);
	OwningCharacter->InputComponent->BindAxis("Vertical", this, &UPlayerMovementComponent::MoveVertical);

	OwningCharacter->InputComponent->BindAction("Slide", EInputEvent::IE_Pressed, this, &UPlayerMovementComponent::StartSlide);
	OwningCharacter->InputComponent->BindAction("Slide", EInputEvent::IE_Released, this, &UPlayerMovementComponent::StopSlide);
}

void UPlayerMovementComponent::MoveHorizontal(float value)
{
	if (PlayerState->ActionState == EActionState::Sliding) return;

	OwningCharacter->AddMovementInput(OwningCharacter->GetActorForwardVector() * value);
	MoveX = value;

	if (MoveX != 0 || MoveY != 0) 
	{
		PlayerState->MoveState = EMoveState::Waling;
	}
	else
	{
		if (PlayerState->MoveState != EMoveState::Idle)
		{
			PlayerState->MoveState = EMoveState::Idle;
		}
	}

	MoveDirection = FVector(MoveX, MoveY, 0);

}

void UPlayerMovementComponent::MoveVertical(float value)
{
	OwningCharacter->AddMovementInput(OwningCharacter->GetActorRightVector() * value);
	MoveY = value;
}






void UPlayerMovementComponent::StartSlide()
{
	if (!OwningCharacter->GetCharacterMovement()->IsMovingOnGround()) return;

	PlayerState->ActionState = EActionState::Sliding;
	OwningCharacter->GetCharacterMovement()->GroundFriction = 1;
	OwningCharacter->GetCharacterMovement()->AddImpulse(OwningCharacter->GetActorForwardVector()* SlideSpeed, true);

}

void UPlayerMovementComponent::StopSlide()
{
	PlayerState->ActionState = EActionState::None;
	OwningCharacter->GetCharacterMovement()->GroundFriction = 8;
	OwningCharacter->GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void UPlayerMovementComponent::LookAtMouse()
{
	

	APlayerController* player_controller = static_cast<APlayerController*>(OwningCharacter->GetController());

	FHitResult Hit;

	

	
	player_controller->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_GameTraceChannel1), true, Hit);

	FVector ActorLocation = OwningCharacter->GetActorLocation();

    FVector MouseLocation = Hit.Location;

	MouseNormal = Hit.TraceStart - Hit.Location;

	MouseNormal.Normalize();

	//DrawDebugLine(GetWorld(), Hit.TraceStart, Hit.Location, FColor::Emerald, true, -1, 0, 10);

	float zOffset = ActorLocation.Z - MouseLocation.Z;

	MouseLocation = MouseLocation + (MouseNormal * ActorLocation.Z);

	MouseToWorldPosition = MouseLocation;

	
	//DrawDebugSphere(GetWorld(), MouseLocation, 200, 26, FColor(181, 0, 0), true, -1, 0, 2);
	


	

	float NewYaw = UKismetMathLibrary::FindLookAtRotation(ActorLocation, MouseLocation).Yaw;

	OwningCharacter->GetMesh()->SetWorldRotation(FRotator(0, NewYaw-90, 0));
	
	player_controller->bShowMouseCursor = true;

	LookRotation = OwningCharacter->GetMesh()->GetComponentRotation();
	

	

		
}

