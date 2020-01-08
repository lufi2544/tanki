// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
    {


        auto AIForwardIntention = MoveVelocity.GetSafeNormal();
        auto TankForwardVector = GetOwner()->GetActorForwardVector().GetSafeNormal();

          DotVectorAngle = FVector::DotProduct(TankForwardVector,AIForwardIntention);

          FVector CrossProSides = FVector::CrossProduct(TankForwardVector,AIForwardIntention);

          IntendMoveSides(CrossProSides.Z);


         UE_LOG(LogTemp,Warning,TEXT("%f"),DotVectorAngle);

         IntendMoveForward(DotVectorAngle);


    }

void UTankMovementComponent:: IntendMoveForward(float Throw)
        {
             if (!RightTrack || !LeftTrack)
        {
            UE_LOG(LogTemp,Error, TEXT("TRacks References fail"));
            return;
        }else
        {
          LeftTrack->SetThrottle(Throw);
          RightTrack->SetThrottle(Throw);
        }
        

        //TODO Avoid double speed caused by double controller input

        }

void UTankMovementComponent::Initialise(UTankTrack* RightTrackToSet, UTankTrack* LeftTrackToSet)
    {
 
        RightTrack = RightTrackToSet;
        LeftTrack = LeftTrackToSet;
        
    }

    
FString UTankMovementComponent::IntendMoveSides(float Throw)
        {
            FString TurnedSide;  

             if (!RightTrack || !LeftTrack)

            {

            UE_LOG(LogTemp,Error, TEXT("TRacks References fail"));

            return FString( "Error");

              }else{
            
                  
            LeftTrack->SetThrottle(Throw);
            RightTrack->SetThrottle(-Throw);

             if (Throw<0)
              {
                TurnedSide = "Left";

    
            }
              else if (Throw > 0)
                 {

               TurnedSide = "Right";

                }else
             {

             TurnedSide = "Idle";

                 }
             }
        
        //TODO Avoid double speed caused by double controller input


            return TurnedSide;
        }

