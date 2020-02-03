// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"
#include "UObject/ConstructorHelpers.h"


UTankTurret::UTankTurret()
{
ConstructorHelpers::FObjectFinder<UStaticMesh>TankTurretFinder(TEXT("StaticMesh'/Game/Tank/tank_fbx_Turret.tank_fbx_Turret'"));
ConstructorHelpers::FObjectFinder<UStaticMesh>MortarTurretFinder(TEXT("StaticMesh'/Game/Mortar/mortar_dome.mortar_dome'"));

if(!ensure(TankTurretFinder.Object)){return;}

if(TankTurretFinder.Object)
{

SetStaticMesh(TankTurretFinder.Object);

}

}


void UTankTurret::Rotatate(float RotationDegrees)
    {

        RotationDegrees = FMath::Clamp<float>(RotationDegrees,-1,+1);
       auto RotationChange =  RotationDegrees * DegreesPerSecond * GetWorld()->DeltaTimeSeconds;
       auto CurrentRotation = RelativeRotation.Yaw + RotationChange;

       SetRelativeRotation(FRotator(0,CurrentRotation,0));

    }
