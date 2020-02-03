// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"


UENUM()
enum class ETurretMesh : uint8
{
Tank,
Mortar
};

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	/**
	 * The Static Mesh reference to build the Turret
	*/
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly,Category ="Set Up")
	ETurretMesh TurretMesh;


	UPROPERTY(EditDefaultsOnly, Category= SetUp)
	float MaxDegrees= 180;

	UPROPERTY(EditDefaultsOnly, Category= SetUp)
	float MinDegrees = -180;

	UPROPERTY(EditDefaultsOnly, Category= SetUp)
	float DegreesPerSecond = 15;


	void Rotatate(float RotationDegrees);


private:

	UTankTurret();
	
};
