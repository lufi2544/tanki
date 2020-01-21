// Fill out your copyright notice in the Description page of Project Settings.


#include "Proyectile.h"
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


 void UTankAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) 
{


	 bool IsReloaded = (FPlatformTime::Seconds() - LastTimeReloaded > ReloadTimeSeconds);


	 if (FPlatformTime::Seconds() - LastTimeReloaded < ReloadTimeSeconds) 
	 {
	 
		 FiringState = EFiringState::Reloading;
	 
	 }
	 else if (IsBarrelMoving())
	 {

		 FiringState = EFiringState::Moving;

	 }
	 else
	 {
		 FiringState = EFiringState::Locked;
	 }
	

}

 void UTankAimingComponent::BeginPlay() 
	{
 

	// The Tanks don�t shoot until at least 3 seconds has passed.
	 LastTimeReloaded = FPlatformTime::Seconds();
 
	}




void UTankAimingComponent::AimAt(FVector AimLocation)
{

	if (!ensure(Barrel)) { return;}
	

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

		if (SuggestProyectileVelocity)
		{
			 AimDirection = out_LaunchVelocity.GetSafeNormal();

			MoveBarrelTowards(AimDirection);


		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Did�t hit anything!"));
		}


}
void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	if (!ensure(BarrelToSet)) {

		UE_LOG(LogTemp, Error, TEXT("Barrel Not Found"));
	}
	else
	{
		Barrel = BarrelToSet;
	}

}


void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	if (!ensure(TurretToSet))
	{
		UE_LOG(LogTemp, Warning, TEXT("Turret Not Found"));
	}
	else
	{
		Turret = TurretToSet;
	}
}


void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{

	if (!ensure(Barrel) || !ensure(Turret)) { return; }


	auto TankName = GetOwner()->GetName();
	auto BarrelCurrentRotation = Barrel->GetForwardVector().Rotation();
	auto AimDirectionRotation = AimDirection.Rotation();
	auto DeltaRotator = AimDirectionRotation - BarrelCurrentRotation;


		//Elevate thee Barrel
		Barrel->Elevate(DeltaRotator.GetNormalized().Pitch);

		//Rotate the Barrel
		Turret->Rotatate(DeltaRotator.GetNormalized().Yaw);


	



	//Given a max elevation speed and the frame time

}

void UTankAimingComponent::Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	if(!ensure((BarrelToSet) || !ensure(TurretToSet)))
	{

		UE_LOG(LogTemp, Error, TEXT("There is no barrel or turret reference found!!"));

	}
	else
	{
		Barrel = BarrelToSet;
		Turret = TurretToSet;

	}
}


UTankBarrel* UTankAimingComponent::GetBarrelReference() { return Barrel; }

void UTankAimingComponent::Fire() 
	{
		if (!ensure(Barrel)|| !ensure(Turret) || !ensure(ProyectileBlueprint)) 
			{

			UE_LOG(LogTemp, Error, TEXT("Fire error"));
			return;
			}


		if (FiringState != EFiringState::Reloading) {

			FVector ProyectileSocketLocation = Barrel->GetSocketLocation(FName("Proyectile"));
			FRotator ProyectileSocketRotation = Barrel->GetSocketRotation(FName("Proyectile"));


			//Spawn a Proyectile on the socjet of the barrel

			auto Proyectile = GetWorld()->SpawnActor<AProyectile>(
				ProyectileBlueprint,
				ProyectileSocketLocation,
				ProyectileSocketRotation
				);

			Proyectile->FireProyectile(LaunchSpeed);

			LastTimeReloaded = FPlatformTime::Seconds();


		}

	}


bool UTankAimingComponent::IsBarrelMoving() 
	{

	FVector BarreFwd = Barrel->GetForwardVector();

	auto Success = AimDirection.Equals(BarreFwd, 0.09f);


	if (Success)
	{


		UE_LOG(LogTemp, Warning, TEXT("Moving"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("not"));
	}

	return !Success;
	}
