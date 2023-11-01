// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/KismetMathLibrary.h"
#include "PlayerShootingComponent.h"

UPlayerShootingComponent::UPlayerShootingComponent()
{
}

void UPlayerShootingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (ShootHeld && IsShooting)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hello"));
		SpawnBullet();
	}
}

void UPlayerShootingComponent::BeginPlay()
{
	Super::BeginPlay();
	Inventory = OwningCharacter->GetComponentByClass<UPlayerInventoryComponent>();
	Movement = OwningCharacter->GetComponentByClass<UPlayerMovementComponent>();
	SetupPlayerInputComponent();
}

void UPlayerShootingComponent::SetupPlayerInputComponent()
{
	OwningCharacter->InputComponent->BindAction("Attack", EInputEvent::IE_Pressed, this, &UPlayerShootingComponent::ShootPressed);
}

void UPlayerShootingComponent::ShootPressed()
{
	
	if (!Inventory->CurrentWeapon) return;

	if (Inventory->CurrentWeapon->WeaponType != EWeaponType::Primary && Inventory->CurrentWeapon->WeaponType != EWeaponType::Secondary) return;
	
	Gun = Cast<AGun>(Inventory->CurrentWeapon);

	if (IsValid(Gun)) 
	{
		ShootHeld = true;
		IsShooting = true;
	}
}

void UPlayerShootingComponent::SpawnBullet()
{
	FVector Position = Gun->BulletSpawn->GetComponentLocation();

	FActorSpawnParameters SpawnInfo;

	float zOffset = Position.Z - Movement->MouseToWorldPosition.Z;
	
	FVector NewMousePosition = Movement->MouseToWorldPosition ;
	UE_LOG(LogTemp, Warning, TEXT("Mouse Z %f"), NewMousePosition.Z);
	UE_LOG(LogTemp, Warning, TEXT("Bullet Z %f"), Position.Z);
	DrawDebugLine(GetWorld(), Position, NewMousePosition, FColor::Emerald, true, -1, 0, 10);

	FRotator NewYaw = UKismetMathLibrary::FindLookAtRotation(Position, NewMousePosition);
	//NewYaw.Yaw -= 90;

	ABullet* newBullet = GetWorld()->SpawnActor<ABullet>(Gun->Bullet,Position, NewYaw, SpawnInfo);

	newBullet->Mesh->AddImpulse(-newBullet->GetActorRightVector() * Gun->BulletVelocity);
	IsShooting = false;
}
