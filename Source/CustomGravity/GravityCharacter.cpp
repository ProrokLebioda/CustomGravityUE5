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
			// For Cylinder objects there is a special case
			if (IsOutward)
			{
				auto actor_location = GetActorLocation();

				// Not sure which way is faster: FMath of UKismetMathLibrary, choose one
				/*auto target_location = FMath::ClosestPointOnInfiniteLine(TargetGravityActor->GetActorLocation() - TargetGravityActor->GetActorUpVector() * 10000.0f,
					TargetGravityActor->GetActorLocation() + TargetGravityActor->GetActorUpVector() * 10000.0f,
					actor_location);*/

				auto target_location = UKismetMathLibrary::FindClosestPointOnLine(actor_location, TargetGravityActor->GetActorLocation(), TargetGravityActor->GetActorUpVector());
				
				//auto target_location = TargetGravityActor->GetActorLocation();
				// We want it to go outwards
				TargetGravityDirection = (target_location - actor_location) * -1;
				TargetGravityDirection.Normalize();
				MovementComponent->SetGravityDirection(FMath::Lerp(MovementComponent->GetGravityDirection(), TargetGravityDirection, LerpAlpha));
			}
			else
			{
				auto actor_location = GetActorLocation();
				auto target_location = TargetGravityActor->GetActorLocation();
				TargetGravityDirection = target_location - actor_location;
				TargetGravityDirection.Normalize();

				MovementComponent->SetGravityDirection(FMath::Lerp(MovementComponent->GetGravityDirection(), TargetGravityDirection, LerpAlpha));
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

void AGravityCharacter::SetTargetGravityActor(AActor* actor, bool is_outward)
{
	TargetGravityActor = actor;
	IsOutward = is_outward;
	// Currently used to reset gravity to downward. 
	// Perhaps in near future it should use saved previous_gravity_direction to revert on exit, but there could be some issues with that as well
	if (!actor)
	{
		SetTargetGravity(FVector::DownVector);
	}
}

AActor* AGravityCharacter::GetTargetGravityActor()
{
	return TargetGravityActor;
}

