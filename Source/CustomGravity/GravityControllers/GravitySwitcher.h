// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "GravitySwitcher.generated.h"

UCLASS()
class CUSTOMGRAVITY_API AGravitySwitcher : public AActor
{
	GENERATED_BODY()




	
public:	
	// Sets default values for this actor's properties
	AGravitySwitcher();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;
};
