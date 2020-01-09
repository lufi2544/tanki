

#include "TankTrack.h"
#include "TankMovementComponent.h"
#include "TankTurret.h"
#include "TankBarrel.h"
#include "GameFramework/Character.h"
#include "Proyectile.h"
#include "Tank.h"

// Sets default
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TankAiminngComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	




}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ATank::AimAt(FVector ObjectVector) const
{

	TankAiminngComponent->AimAt(ObjectVector,LaunchSpeed);

}

void ATank::SetBarrelReference(UTankBarrel* BarrellToSet)
{

TankAiminngComponent->SetBarrelReference(BarrellToSet);

//Local Reference to Barrel
Barrel = BarrellToSet;

}

void ATank::SetTurretReference(UTankTurret* TankTurret){

	TankAiminngComponent->SetTurretReference(TankTurret);


}

void ATank::Fire()
	{
			
			bool IsReloaded = (FPlatformTime::Seconds() - LastTimeReloaded > ReloadTimeSeconds);
			



			if(Barrel && IsReloaded){
				
		
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

