// Fill out your copyright notice in the Description page of Project Settings.


#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "TankTrack.h"


UTankTrack::UTankTrack()
    {
            ConstructorHelpers::FObjectFinder<UStaticMesh>StaticmeshFinder(TEXT("StaticMesh'/Game/Tank/tank_fbx_Track.tank_fbx_Track'"));

        if(StaticmeshFinder.Object)
            {

                UStaticMesh* TrackAsset= StaticmeshFinder.Object;

                this->SetStaticMesh(TrackAsset);
                   


            }else
            {
                UE_LOG(LogTemp,Error,TEXT("There is No Track Mesh Found"));
            }
    }


    void UTankTrack::SetThrottle(float Throttle)
        {


                auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
                auto ForceLocation = GetComponentLocation();
                auto TankPrimitiveComponent =Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

                TankPrimitiveComponent->AddForceAtLocation(
                    ForceApplied,
                    ForceLocation
                );

        }
