// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}




void UTankAimingComponent::AimAt(FVector AimLocation, float LaunchSpeed)
	{

		if(!Barrel){return;}

		FVector out_LaunchVelocity;
		TArray<AActor*>ActorstoIgnore;
		ActorstoIgnore.Add(GetOwner());

		bool SuggestProyectileVelocity = UGameplayStatics::SuggestProjectileVelocity(
 
				this,
				out_LaunchVelocity,
				Barrel->GetSocketLocation(FName("Proyectile")),
				AimLocation,
				LaunchSpeed,
				false,
				0,
				0,
				ESuggestProjVelocityTraceOption::DoNotTrace,
				FCollisionResponseParams::DefaultResponseParam
				
		);
		

		if(SuggestProyectileVelocity)
			{
					auto AimDirection = out_LaunchVelocity.GetSafeNormal();

					MoveBarrelTowards(AimDirection);

			}else
			{
				UE_LOG(LogTemp,Warning,TEXT("False"));
			}
			
		
		


		

		

	}
	void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
		{
			if(!BarrelToSet){

				UE_LOG(LogTemp,Error,TEXT("Barrel Not Found"));
			}else
			{
				Barrel=BarrelToSet;
			}
			
		}


	void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
		{
		if (!TurretToSet)
		{
			UE_LOG(LogTemp,Warning,TEXT("Turret Not Found"));
		}else
		{
			Turret = TurretToSet;
		}
		
		
			


		}


	void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
		{

				auto TankName = GetOwner()->GetName();
				auto BarrelCurrentRotation = Barrel->GetForwardVector().Rotation();
				auto AimDirectionRotation = AimDirection.Rotation();
				auto DeltaRotator = AimDirectionRotation - BarrelCurrentRotation ;


			//Move th ebarrel the roght amount this frame
			if (Barrel){
			Barrel->Elevate(DeltaRotator.GetNormalized().Pitch);
			}
			else
			{
				UE_LOG(LogTemp,Error,TEXT("No Barrel Reference Found"));
			}

			if(Turret){
			Turret->Rotatate(DeltaRotator.GetNormalized().Yaw);

			}else
			{
				UE_LOG(LogTemp,Error,TEXT("No Turret Reference Found"));
			}
			


			//Given a max elevation speed and the frame time

			 



		}
