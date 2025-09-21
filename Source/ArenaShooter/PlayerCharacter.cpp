// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCharacterCamera"));

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	CameraComponent->SetRelativeLocationAndRotation(FVector(0.0, 10.0, 0.0), FRotator(0.0, 90.0, 0.0));
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	double mouseX;
	double mouseY;
	GetWorld()->GetFirstPlayerController()->GetInputMouseDelta(mouseX, mouseY);
	CameraComponent->AddLocalRotation(FRotator(1.0 * mouseY, 0.0, 0.0));
	AddActorLocalRotation(FRotator(0.0, 1.0 * mouseX, 0.0));
	double movementBackForth = 0.0;
	if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::W)) {
		movementBackForth += 1.0;
	}
	if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::S)) {
		movementBackForth -= 1.0;
	}
	double movementLeftRight = 0.0;
	if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::D)) {
		movementLeftRight += 1.0;
	}
	if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::A)) {
		movementLeftRight -= 1.0;
	}
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

