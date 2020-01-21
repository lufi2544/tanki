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

	bool IsBarrelMoving();

	FVector AimDirection;


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





};
