// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


class UTankBArrel;
class UTankTurret;
class AProyectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()





public:



	UFUNCTION(Blueprintcallable, Category = Controls)
		void Fire();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	ATank();

		//TODO remove opnce fire has been removed
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