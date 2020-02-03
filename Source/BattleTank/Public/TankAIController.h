// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 *
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetPawn(APawn* InMesh)override;

private:

	//Maximum approach to the Player Tank
	UPROPERTY(EditAnywhere, Category = "AI")
		float AproachAmount = 8000;

	//TODO BP assign does not work properly

	UFUNCTION()
	void OnTankDeath();

};