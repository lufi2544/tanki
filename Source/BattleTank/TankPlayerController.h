// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Controller.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()


	public:

	 virtual void BeginPlay() override;
	 virtual void Tick(float DeltaSeconds) override ;

	 UFUNCTION(BlueprintPure, Category = "SetUp")
		 ATank* GetControlledTank() const;

	


	protected:

	


		


	 private:

	 void AimTowardsCrosshair( );
	 bool GetSightRayHitLocation( ) const;
	 bool GetIfCrossHairTurretImpact(FVector& out_HitLocation) const;
	 bool GetLookDirection(FVector2D CrossHairScreenLocation, FVector& LookDirection) const;
	 bool GetLookVectorHitResult(FVector LookDirection,FHitResult& out_HitLocation) const;
	 FVector GetTurretReach(FVector	StartLocation, FVector LookDirection) const;
	 

	 	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;

		UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.425;

		UPROPERTY(EditAnywhere)
		float ReachLocation = 100000000;
};
