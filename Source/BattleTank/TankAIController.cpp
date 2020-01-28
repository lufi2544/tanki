// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankPlayerController.h"
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

                auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
                APawn* AITank = GetPawn();

                auto TankAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

                auto PlayerAimingComponent = PlayerTank ->FindComponentByClass<UTankAimingComponent>();
                   
                   
                    if(!ensure(PlayerTank && AITank)){return;}
                    
                      MoveToActor(PlayerTank,AproachAmount );
                 
                   TankAimingComponent->AimAt(PlayerTank->GetActorLocation());

                  if(TankAimingComponent->GetFiringState()== EFiringState::Locked)
                    {

                         UE_LOG(LogTemp,Warning,TEXT("FIRE!!"));

                        TankAimingComponent->Fire();
                         

                    }

                

          }
        

    