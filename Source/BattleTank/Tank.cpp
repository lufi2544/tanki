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
	PrimaryActorTick.bCanEverTick = false;

	//TODO eliminate the subobject and test in a way that we make a UPROPERTY from a UAimingComponent and BlueprintReadOnly, then use that variable for the UI.


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










