// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "Engine/World.h"
#include "CollisionQueryParams.h"
#include "TankPlayerController.h"
#include "Tank.h"





void ATankPlayerController::BeginPlay()
        {

            Super::BeginPlay();

            auto Tank = GetControlledTank();

            if (!Tank)
            {
            UE_LOG(LogTemp,Error,TEXT("No Tank Possesed!"));

            }
            else{
            UE_LOG(LogTemp,Warning,TEXT("%s"),*Tank->GetName());
            }

           
        }

void ATankPlayerController::Tick(float DeltaSeconds) 
    {

        Super::Tick(DeltaSeconds);

        FVector HitLocation;

            if (GetIfCrossHairTurretImpact(HitLocation))
            {
              
                GetControlledTank()->AimAt(HitLocation);

            }else
            {
                GetControlledTank()->AimAt(FVector(0,0,0));
            }
            

        
    }       

ATank* ATankPlayerController::GetControlledTank() const
    {
    ATank* Tank = Cast<ATank>(GetPawn()); 

    return Tank;
    }

    void ATankPlayerController::AimTowardsCrosshair()
        {
            if (!GetControlledTank()){ return; }

            //Get linetrace location if linetrace hits trought crosshair
            //If it hits the landscape
            //tell controlled tank to aim at this point
    
        }

    bool ATankPlayerController::GetIfCrossHairTurretImpact(FVector& out_HitLocation)  const
            {           
                    //Find CrossHair Postioin on the ViewPort
                    int32 ViewPortXSize, ViewPortYSize;
                    FVector2D CrossHairScreenVector;

                 /*OUT*/ GetViewportSize(ViewPortXSize,ViewPortYSize);

                    CrossHairScreenVector = FVector2D(ViewPortXSize * CrossHairXLocation, ViewPortYSize * CrossHairYLocation); // We declare on the constructor the sizes we want the vector2D to has.

                    //Deproyects the CrossHair into the World Direction 2d-3d

                    FVector LookDirection;
                    FHitResult HitLocation;

                    if(GetLookDirection(CrossHairScreenVector,LookDirection))
                    {
                           if(GetLookVectorHitResult(LookDirection,HitLocation))
                           {
                               out_HitLocation=HitLocation.Location;

                               return true;

                           }else
                           {
                               return false;
                           }
                           
                    }

                return false;
            }

            bool ATankPlayerController::GetLookDirection(FVector2D CrossHairScreenLocation, FVector& LookDirection) const
            {
                FVector CameraLocation;

               return DeprojectScreenPositionToWorld(CrossHairScreenLocation.X,CrossHairScreenLocation.Y,CameraLocation,LookDirection);
    
            }

           bool ATankPlayerController::GetLookVectorHitResult(FVector LookDirection,FHitResult& out_HitLocation)const
           {
               FCollisionQueryParams QueryParams = FCollisionQueryParams(TEXT(""),false,GetControlledTank());

        
                FVector StartLocation = PlayerCameraManager->GetCameraLocation();
                bool HIT = GetWorld()->LineTraceSingleByChannel(

                        out_HitLocation,
                        StartLocation,
                        GetTurretReach(StartLocation,LookDirection),
                        ECollisionChannel::ECC_PhysicsBody,
                        QueryParams
                );


                

                return HIT;
           }


         FVector ATankPlayerController::GetTurretReach(FVector StartLocation, FVector LookDirection)const
            {return StartLocation + (LookDirection * ReachLocation) ;}


