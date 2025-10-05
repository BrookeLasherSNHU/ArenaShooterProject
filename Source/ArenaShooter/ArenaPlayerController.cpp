// Fill out your copyright notice in the Description page of Project Settings.


#include "ArenaPlayerController.h"
#include "PlayerCharacter.h"
#include <GameFramework/PlayerInput.h>
#include <Camera/CameraComponent.h>




AArenaPlayerController::AArenaPlayerController() : Super() { 
}


void AArenaPlayerController::PlayerTick(float DeltaTime)
{
	double mouseX;
	double mouseY;
	GetInputMouseDelta(mouseX, mouseY);
	double movementBackForth = 0.0;
	if (IsInputKeyDown(EKeys::W)) {
		movementBackForth += 1.0;
	}
	if (IsInputKeyDown(EKeys::S)) {
		movementBackForth -= 1.0;
	}
	double movementLeftRight = 0.0;
	if (IsInputKeyDown(EKeys::D)) {
		movementLeftRight += 1.0;
	}
	if (IsInputKeyDown(EKeys::A)) {
		movementLeftRight -= 1.0;
	}
	
	((APlayerCharacter*)GetPawn())->CameraComponent->AddLocalRotation(FRotator(mouseY/DeltaTime, 0.0, 0.0));
	GetPawn()->AddActorWorldRotation(FRotator(0.0, mouseX/DeltaTime, 0.0));
	// UE_LOG(LogTemp, Warning, TEXT("%f %f %f %f"), movementBackForth, movementLeftRight, mouseX, mouseY);
	GetPawn()->AddMovementInput(FVector(movementBackForth, movementLeftRight, 0.0));
	
}
