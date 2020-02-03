// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
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
    auto PlayerAimingComponent = PlayerTank->FindComponentByClass<UTankAimingComponent>();

    if (!ensure(TankAimingComponent)) { return; }


    if (!ensure(PlayerTank && AITank)) { return; }

    MoveToActor(PlayerTank, AproachAmount);

    TankAimingComponent->AimAt(PlayerTank->GetActorLocation());


    if (TankAimingComponent->GetFiringState() == EFiringState::Locked)
    {



        TankAimingComponent->Fire();


    }



}

void ATankAIController::SetPawn(APawn* InPawn) 
    {
    Super::SetPawn(InPawn);

    if (InPawn)
        {
        auto AITank = Cast<ATank>(InPawn);
            
        if (!ensure(AITank)){return;}

        AITank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnTankDeath);
            
    
        }

    }

void ATankAIController::OnTankDeath() 
    {
    
    UE_LOG(LogTemp,Warning,TEXT("Delegating from AI."));

    }
