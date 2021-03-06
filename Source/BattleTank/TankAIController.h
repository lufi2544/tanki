// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;
class ATankPlayerController;
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

	private:

	ATankPlayerController* GetTankPlayerController();



	//Maximum approach to the Player Tank
	UPROPERTY(EditDefaultsOnly, Category= "AI Movement")
	float AproachAmount = 3000;
	
	
	
};
