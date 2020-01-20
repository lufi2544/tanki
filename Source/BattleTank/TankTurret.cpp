// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"
#include "UObject/ConstructorHelpers.h"


UTankTurret::UTankTurret()
{
ConstructorHelpers::FObjectFinder<UStaticMesh>StaticMeshFinder(TEXT("StaticMesh'/Game/Tank/tank_fbx_Turret.tank_fbx_Turret'"));

if(StaticMeshFinder.Object){

this->SetStaticMesh(StaticMeshFinder.Object);

    }else
    {
        UE_LOG(LogTemp,Error,TEXT("No Turret Static Mesh Found"));
    }
    
}


void UTankTurret::Rotatate(float RotationDegrees)
    {

        RotationDegrees = FMath::Clamp<float>(RotationDegrees,-1,+1);
       auto RotationChange =  RotationDegrees * DegreesPerSecond * GetWorld()->DeltaTimeSeconds;
       auto CurrentRotation = RelativeRotation.Yaw + RotationChange;

       SetRelativeRotation(FRotator(0,CurrentRotation,0));

    }
