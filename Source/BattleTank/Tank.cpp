#include "TankTrack.h"
#include "TankTurret.h"
#include "TankBarrel.h"
#include "GameFramework/Character.h"
#include "Proyectile.h"
#include "Tank.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//TODO eliminate the subobject and test in a way that we make a UPROPERTY from a UAimingComponent and BlueprintReadOnly, then use that variable for the UI.



	UE_LOG(LogTemp, Error, TEXT("%s Donkey c++ Begin Constructor"),*GetName());

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();




	UE_LOG(LogTemp,Error, TEXT("Donkey c++ Begin play"));


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



void ATank::Fire()
{
	if (!ensure(Barrel)) {
	
		UE_LOG(LogTemp, Error, TEXT("Fire error"));
		return;
	}
	else
	{

	

		bool IsReloaded = (FPlatformTime::Seconds() - LastTimeReloaded > ReloadTimeSeconds);


		if (Barrel && IsReloaded) {


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
		else
		{
			UE_LOG(LogTemp,Warning,TEXT("Haven´t reloaded yet or no barrl reference found!"));
		}
		
	}

}







