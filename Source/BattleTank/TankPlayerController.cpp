

#include "TankAimingComponent.h"
#include "BattleTank.h"
#include "Engine/World.h"
#include "CollisionQueryParams.h"
#include "TankPlayerController.h"





void ATankPlayerController::BeginPlay()
{

    Super::BeginPlay();
    
    auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
 


    if (!ensure(AimingComponent))
        {
        UE_LOG(LogTemp, Warning, TEXT("Player Controller class didn´t find a Aiming Component"));
    
    
    }
    else
    {
        FoundAimingComponent(AimingComponent);

        TankAimingComponent = AimingComponent;

    }


}

void ATankPlayerController::Tick(float DeltaSeconds)
{

    Super::Tick(DeltaSeconds);

    FVector HitLocation;

    if (GetIfCrossHairTurretImpact(HitLocation))
    {

      // GetControlledTank()->AimAt(HitLocation);

        TankAimingComponent->AimAt(HitLocation);
       

    }
    else
    {
       // GetControlledTank()->AimAt(FVector(0, 0, 0));

        TankAimingComponent->AimAt(FVector(0, 0, 0));
    }



}



void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetPawn()) { return; }

    //Get linetrace location if linetrace hits trought crosshair
    //If it hits the landscape
    //tell controlled tank to aim at this point

}

bool ATankPlayerController::GetIfCrossHairTurretImpact(FVector& out_HitLocation)  const
{
    //Find CrossHair Postioin on the ViewPort
    int32 ViewPortXSize, ViewPortYSize;
    FVector2D CrossHairScreenVector;

    /*OUT*/ GetViewportSize(ViewPortXSize, ViewPortYSize);

    CrossHairScreenVector = FVector2D(ViewPortXSize * CrossHairXLocation, ViewPortYSize * CrossHairYLocation); // We declare on the constructor the sizes we want the vector2D to has.

    //Deproyects the CrossHair into the World Direction 2d-3d

    FVector LookDirection;
    FHitResult HitLocation;

    if (GetLookDirection(CrossHairScreenVector, LookDirection))
    {
        if (GetLookVectorHitResult(LookDirection, HitLocation))
        {
            out_HitLocation = HitLocation.Location;

            return true;

        }
        else
        {

            return false;
        }

    }

    return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D CrossHairScreenLocation, FVector& LookDirection) const
{
    FVector CameraLocation;

    return DeprojectScreenPositionToWorld(CrossHairScreenLocation.X, CrossHairScreenLocation.Y, CameraLocation, LookDirection);

}

bool ATankPlayerController::GetLookVectorHitResult(FVector LookDirection, FHitResult& out_HitLocation)const
{
    FCollisionQueryParams QueryParams = FCollisionQueryParams(TEXT(""), false, GetPawn());


    FVector StartLocation = PlayerCameraManager->GetCameraLocation();
    bool HIT = GetWorld()->LineTraceSingleByChannel(

        out_HitLocation,
        StartLocation,
        GetTurretReach(StartLocation, LookDirection),
        ECollisionChannel::ECC_PhysicsBody,
        QueryParams
    );




    return HIT;
}


FVector ATankPlayerController::GetTurretReach(FVector StartLocation, FVector LookDirection)const
{
    return StartLocation + (LookDirection * ReachLocation);
}
