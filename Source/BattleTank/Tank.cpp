#include "Tank.h"
#include "GameFramework/Character.h"


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


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}










