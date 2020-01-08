// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Elevate(float RelativeSpeed);

	private:
		//Maximum Elevation of the Barrel in Degrees
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxElevation = 25;
	//Minumum Elevation of the Barrel in Degrees
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinElevation = 0;



	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 5;
	
	//  Sensible default
private:
 UTankBarrel();

};
