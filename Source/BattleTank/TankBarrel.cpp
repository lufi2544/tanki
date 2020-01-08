// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"
#include "TankBarrel.h"


UTankBarrel::UTankBarrel()
{

ConstructorHelpers::FObjectFinder<UStaticMesh>StaticMeshFinder(TEXT("StaticMesh'/Game/Tank/tank_fbx_Barrel.tank_fbx_Barrel'"));


if(StaticMeshFinder.Object)
{

this->SetStaticMesh(StaticMeshFinder.Object);


}
}


void UTankBarrel::Elevate(float RelativeSpeed)
    {
           auto CRelativeSpeed = FMath::Clamp<float>(RelativeSpeed,-1,+1);
           auto ElevationChange = CRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
           auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
           auto ClampedNewElevation= FMath::Clamp<float>(RawNewElevation,MinElevation,MaxElevation);

           SetRelativeRotation(FRotator (ClampedNewElevation, 0 , 0));


    }

