// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGravity/Actors/Interactables/InteractableBox.h"

// Sets default values
AInteractableBox::AInteractableBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AInteractableBox::BeginPlay()
{
	Super::BeginPlay();
	
}


void AInteractableBox::Interact()
{
	UE_LOG(LogTemp, Warning, TEXT("Interacting with a box"));
}

