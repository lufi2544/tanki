// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8 
	{
	Reloading,
	Moving,
	Locked
};

class UTankBarrel; //Forward declaration
class UTankTurret;

//Holds Barrel´s properties and Elevate Method
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()
private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;


public:
	// Sets default values for this component's properties
	UTankAimingComponent();
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void AimAt(FVector AimLocation, float LaunchSpeed);
	void MoveBarrelTowards(FVector AimDirection);
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable,Category = " Set Up")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

protected:

	UPROPERTY(BlueprintReadOnly)
	EFiringState FiringState = EFiringState::Reloading;
	


};
