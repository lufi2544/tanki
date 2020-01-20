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
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories="Sockets")
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
	void AimAt(FVector AimLocation);
	void MoveBarrelTowards(FVector AimDirection);
	void SetTurretReference(UTankTurret* TurretToSet);
	UTankBarrel* GetBarrelReference();

	UFUNCTION(BlueprintCallable, Category = " Set Up")
		void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	/* If the AimingComponent on the Tank is found then the event is executed*/
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Aiming")
		EFiringState FiringState = EFiringState::Moving;


protected:

	

	//TODO remove opnce fire has been removed
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 10000;



};
