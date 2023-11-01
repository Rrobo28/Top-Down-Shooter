// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerState.h"

UMyPlayerState::UMyPlayerState()
{


}

void UMyPlayerState::BeginPlay()
{
	Super::BeginPlay();

	MoveState = EMoveState::Idle;
	ActionState = EActionState::None;
	JumpState = EJumpState::None;
}
