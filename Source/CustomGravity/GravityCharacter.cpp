// Fill out your copyright notice in the Description page of Project Settings.


#include "GravityCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AGravityCharacter::AGravityCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	IsOutward = false;
	IsDebug = false;
	LerpAlpha = 0.1;
	TargetGravityDirection = FVector::DownVector;

}

// Called when the game starts or when spawned
void AGravityCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGravityCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UCharacterMovementComponent* MovementComponent = GetCharacterMovement();
	if (MovementComponent)
	{
		if (TargetGravityActor != nullptr)
		{
			auto actor_location = GetActorLocation();
			auto target_location = TargetGravityActor->GetActorLocation();
			TargetGravityDirection = target_location - actor_location;
			TargetGravityDirection.Normalize();
		
			// For Cylinder objects there is a special case
			if (IsOutward)
			{
			}
		}
		else
		{
			MovementComponent->SetGravityDirection(FMath::Lerp(MovementComponent->GetGravityDirection(), TargetGravityDirection, LerpAlpha));
		}
	}
}

// Called to bind functionality to input
void AGravityCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGravityCharacter::SetTargetGravity(const FVector direction)
{
	UCharacterMovementComponent* MovementComponent = GetCharacterMovement();
	if (MovementComponent)
	{
		//MovementComponent->SetGravityDirection(direction);
		TargetGravityDirection = direction;
	}
}

