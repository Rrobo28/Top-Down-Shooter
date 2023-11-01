// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseComponent.h"
#include "MyPlayerState.generated.h"

/**
 *
 */
UENUM(BlueprintType)
enum class EMoveState : uint8 {
    Idle        UMETA(DisplayName = "Idle"),
    Waling       UMETA(DisplayName = "Walk"),
    Sprinting        UMETA(DisplayName = "Sprint"),


};

UENUM(BlueprintType)
enum class EJumpState : uint8 {
    None        UMETA(DisplayName = "None"),
    Start       UMETA(DisplayName = "Start"),
    Up        UMETA(DisplayName = "Up"),
    Down       UMETA(DisplayName = "Down"),

};

UENUM(BlueprintType)
enum class EActionState : uint8 {
    None        UMETA(DisplayName = "HeavyAttack"),
    Sliding        UMETA(DisplayName = "Sliding"),
    Throwing       UMETA(DisplayName = "Throwing"),
    Holding        UMETA(DisplayName = "Holding"),
    LightAttack       UMETA(DisplayName = "LightAttack"),
    HeavyAttack        UMETA(DisplayName = "HeavyAttack"),

};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SIMPLEAPOCALYPSE_API UMyPlayerState : public UBaseComponent
{
    GENERATED_BODY()

public:

    UMyPlayerState();

protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    EMoveState MoveState;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    EJumpState JumpState;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    EActionState ActionState;




};

