// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomGravity/InteractionSystem/InteractInterface.h"
#include "InteractableBox.generated.h"

UCLASS()
class CUSTOMGRAVITY_API AInteractableBox : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Inherited via IInteractInterface
	void Interact() override;

};
