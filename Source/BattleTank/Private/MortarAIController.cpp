// Epic Games (Employee : Juan Esteban Rayo Contreras)


#include "MortarAIController.h"
#include "Tank.h"
#include "Mortar.h"
#include "TankAimingComponent.h"
#include "TankPlayerController.h"
#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"


void AMortarAIController::BeginPlay()

{
    Super::BeginPlay();



}

void AMortarAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);


    auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

    if (!ensure(PlayerTank)) { return; }

    APawn* AIMortar = GetPawn();
    auto MortarAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

    if (!ensure(MortarAimingComponent)) { return; }

    auto PlayerAimingComponent = PlayerTank->FindComponentByClass<UTankAimingComponent>();


    if (!ensure(PlayerAimingComponent)) { return; }


    MortarAimingComponent->AimAt(PlayerTank->GetActorLocation());


    if (MortarAimingComponent->GetFiringState() == EFiringState::Locked)
    {
        MortarAimingComponent->Fire();
    }



}

void AMortarAIController::SetPawn(APawn* InPawn)
{
    Super::SetPawn(InPawn);

    if (InPawn)
    {
        auto AIMortar = Cast<AMortar>(InPawn);

        if (!ensure(AIMortar)) { return; }

        AIMortar->OnDeath.AddUniqueDynamic(this,&AMortarAIController::OnMortarDeath);

    }

}

void AMortarAIController::OnMortarDeath()
{

    GetPawn()->DetachFromControllerPendingDestroy();

}

