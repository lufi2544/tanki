// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


class UTankBArrel;
class UTankTurret;
class AProyectile;
class UTankMovementComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()





public:

	//Sets up The Barrel Reference for the Tank
	UFUNCTION(Blueprintcallable, Category = SetUp)
		void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(Blueprintcallable, Category = Controls)
		void Fire();

	//Sets up The Turret Reference for the Tank
	UFUNCTION(BlueprintCallable, Category = SetUp)
		void SetTurretReference(UTankTurret* TankTurret);

	void AimAt(FVector ObjectVector)const;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(BlueprintReadOnly)
		UTankAimingComponent* TankAiminngComponent = nullptr;
	


private:

	ATank();

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 10000;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = SetUp)
		TSubclassOf<AProyectile> ProyectileBlueprint;


	//Local Barrel Reference for spawning proyectile
	UTankBarrel* Barrel = nullptr;



	double LastTimeReloaded = 0;

};
