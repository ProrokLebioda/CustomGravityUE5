// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GravityCharacter.generated.h"

UCLASS()
class CUSTOMGRAVITY_API AGravityCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGravityCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere)
	AActor* TargetGravityActor;
	
	UPROPERTY(EditAnywhere)
	FVector TargetGravityDirection;

	UPROPERTY(EditAnywhere)
	bool IsOutward;

	UPROPERTY(EditAnywhere)
	bool IsDebug;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LerpAlpha;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void SetTargetGravity(const FVector direction);

	UFUNCTION(BlueprintCallable)
	void SetTargetGravityActor(AActor* actor, bool is_outward);
	UFUNCTION(BlueprintCallable)
	AActor* GetTargetGravityActor();
};
