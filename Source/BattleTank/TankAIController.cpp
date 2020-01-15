// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankPlayerController.h"
#include "Tank.h"
#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"


void ATankAIController::BeginPlay()

    {
        Super::BeginPlay();

       

    }

     void ATankAIController::Tick(float DeltaTime)
        {
                Super::Tick(DeltaTime);

                ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
                ATank* AITank = Cast<ATank> (GetPawn());
                   
                   
                    if(!PlayerTank)
                    {
                  UE_LOG(LogTemp,Error,TEXT("There is no Player Tank found"));
                    }else
                    {
                        
                     AITank->AimAt(PlayerTank->GetActorLocation());

                  // AITank->Fire();

                    }
                    


                    if(!AITank)
                         {
                  UE_LOG(LogTemp,Error,TEXT("There is no AI Tank found"));
                         }

                MoveToActor(
                  GetTankPlayerController()->GetControlledTank(),AproachAmount );

          

        }

ATankPlayerController* ATankAIController::GetTankPlayerController()
  {return Cast<ATankPlayerController>(GetWorld()->GetFirstPlayerController()); }

    