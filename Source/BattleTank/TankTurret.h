// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	void Rotatate(float RotationDegrees);

	UPROPERTY(EditDefaultsOnly, Category= SetUp)
	float MaxDegrees= 180;

	UPROPERTY(EditDefaultsOnly, Category= SetUp)
	float MinDegrees = -180;

	UPROPERTY(EditDefaultsOnly, Category= SetUp)
	float DegreesPerSecond = 15;


private:

	UTankTurret();
	
};
