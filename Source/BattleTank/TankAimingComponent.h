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
	Locked,
	Idle
};


//Forward declarations
class AProyectile;
class UTankBarrel; 
class UTankTurret;

//Holds Barrel´s properties and Elevate Method
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories="Sockets")
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()
private:
	


	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void BeginPlay() override;


	FVector AimDirection;
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	/**
	 * @return bool If the barrel is currently moving.
	 *
	*/
	bool IsBarrelMoving();
	float RotationVectorNormalized(float DesiredLocation);

public:
	// Sets default values for this component's properties
	UTankAimingComponent();


	UTankBarrel* GetBarrelReference();

	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void AimAt(FVector AimLocation);
	void MoveBarrelTowards(FVector AimDirection);
	void SetTurretReference(UTankTurret* TurretToSet);

	/*Returns the current Firing State of the Tank*/
	EFiringState GetFiringState() const;

	/**
	 * Initialise the needed components into c++.
	 * @param BarrelToSet Takes the reference of the barrel into c++.
	 * @param TurretToSet Takes the reference of the Turret into c++.
	**/
	UFUNCTION(BlueprintCallable, Category = " Set Up")
		void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	

	//Makes the tank Fire.
	UFUNCTION(Blueprintcallable, Category = Firing)
		void Fire();

protected:

	

	double LastTimeReloaded = 0;

	UPROPERTY(EditAnywhere, Category = Firing)
		float ReloadTimeSeconds = 2;

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 10000;

	UPROPERTY(EditDefaultsOnly, Category = SetUp)
		TSubclassOf<AProyectile> ProyectileBlueprint;

/* If the AimingComponent on the Tank is found then the event is executed*/
	UPROPERTY(BlueprintReadOnly,VisibleAnywhere, Category = "Aiming")
		EFiringState FiringState = EFiringState::Idle ;

};
